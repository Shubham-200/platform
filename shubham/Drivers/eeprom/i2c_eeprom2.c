#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/sysfs.h>
#include <linux/mod_devicetable.h>
#include <linux/log2.h>
#include <linux/bitops.h>
#include <linux/jiffies.h>
#include <linux/of.h>
#include <linux/i2c.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>


MODULE_DESCRIPTION("eeprom Client Driver");
MODULE_AUTHOR("venkatarao");
MODULE_LICENSE("GPL");
MODULE_INFO(intree,"Y");								// ?
#define devname "eeprom"


struct eeprom_data {
	struct i2c_client *client;
	u8 *write_buff;
	u16 write_max;
	dev_t devt;
	struct cdev cdev;
	struct class *class;
};	

static ssize_t eeprom_read(struct file* file, char *buf, size_t count) 
{
	printk("read started\n");
	struct i2c_msg msg;
	char *tmp;
	struct eeprom_data *dev = (struct eeprom_data *)(file->private_data);
	struct i2c_adapter *adap = dev->client->adapter;
	int ret;

	tmp = kmalloc(count, GFP_KERNEL);			// ?

	if (tmp == NULL)
	  return -ENOMEM;

    if (count > 256)
		    count = 256;

	//printk("read started11111\n");
	msg.addr = 0x50; 
	msg.flags = 0x0001; 
	msg.len = count;
	msg.buf = tmp;
	//printk("Invoking Transfer\n");
	msleep(2);
	ret = i2c_transfer(adap, &msg, 1);
        /* for (i = 0; i < 256; i++)
	{
	if (!(i % 16))
	printk("\n");
	printk("   %x", *(tmp+i));
	}   */
       //while (ret<0)
       //ret = i2c_transfer(adap, &msg, 1);
        //printk("read started2222\n");
	if (ret < 0)
	{
		printk("Error: data read from device failed\n");
	 	return 0;
	}
	else	
		ret = copy_to_user(buf, tmp, count) ? -EFAULT : count;

	kfree(tmp);

	printk("\nread completed\n");	
	
	return ret;
}

static ssize_t eeprom_write(struct file* file, const char *buf, size_t count)
{

	printk("write started\n");
	struct eeprom_data *dev = (struct eeprom_data *)(file->private_data);
	struct i2c_adapter *adap = dev->client->adapter;
	 static char *tmp;
	struct i2c_msg msg;
	int ret;
        //int i;
        if (count > 9)
		count = 9;

     	tmp = kzalloc(count, GFP_KERNEL);
	printk(" temp count  %d",count);  
     	if (tmp == NULL)
		return -ENOMEM;
	//printk("write started1111\n");
/*	//, loff_t *pos
	ret=copy_from_user(tmp,buf, count);
        if (ret)
	return PTR_ERR(tmp);	
     	for (i = 0; i < 256; i++)
	{
	if (!(i % 16))
		printk("\n");
		printk("   %x", *(tmp+i));
	}
  */
	tmp = memdup_user(buf, count);
	
	//printk(" user count  %d",count); 
	if (IS_ERR(tmp))
	return PTR_ERR(tmp);
 	//for (i = 0; i < 256; i++){
	msg.addr = 0x50; 
	msg.flags = 0x0000; 
	msg.len = count;
	msg.buf = tmp;
//}
/////////
	//printk(" msg count  %d",count); 

	//ret=i2c_master_send (adap,tmp,count);
	//if(ret<0){
////////
	//printk("error:write started2222  master send failed\n");
	msleep(2);
     	ret = i2c_transfer(adap, &msg,1); 
        if(ret<0)
        //printk("error: write tranfer 2222\n");
  // }	
	kfree(tmp);
	printk("write completed\n");
	return (ret == 1 ? count : ret);
}

static int eeprom_open(struct inode *inode, struct file *file)
{
	struct eeprom_data *dev = container_of(inode->i_cdev, struct eeprom_data, cdev);	// ?
	if (dev == NULL) {
		printk("Error: open failed\n");
		return -1;
	}
	file->private_data = dev;

	return 0;
}

static int eeprom_close(struct inode *inode, struct file *file)
{
	return 0;
}

struct file_operations fops = {
	.open = eeprom_open,
	.release = eeprom_close,
	.read = eeprom_read,
	.write = eeprom_write,
};

static int eeprom_remove(struct i2c_client *client)
{
	printk("Remove started\n");
	struct eeprom_data *dev;
	dev = i2c_get_clientdata(client);
	cdev_del(&dev->cdev);
	device_destroy(dev->class, dev->devt);
	class_destroy(dev->class);
	unregister_chrdev_region(dev->devt, 1);
	printk("Remove completed\n");
	return 0;

}
static int eeprom_probe(struct i2c_client *client, const struct i2c_device_id *id)
{

	printk("Probe started\n");

	struct eeprom_data *data;
	int init_result;

	data = devm_kzalloc(&client->dev, sizeof(struct eeprom_data), GFP_KERNEL);
	data->write_max = 32;
	data->write_buff = devm_kzalloc(&client->dev, data->write_max, GFP_KERNEL);
	i2c_set_clientdata(client, data);
	init_result = alloc_chrdev_region(&data->devt, 0, 1, "eeprom");
	data->client = client;

	if( 0 > init_result )
	{
	printk("Error:Device Registration failed\n");
	return -1;
	}
	printk("Major Nr: %d\n", MAJOR(data->devt));

	if ((data->class = class_create(THIS_MODULE, "eeprom")) == NULL)
	{
	printk("Error:class creat faileed\n");
	return -1;
	}
	if(device_create(data->class, NULL, data->devt, NULL, "eeprom") == NULL)
	{
	printk("Error:device create faileed\n");
	return -1;
	}
	
	cdev_init(&data->cdev, &fops);

	if(cdev_add(&data->cdev, data->devt, 1) <0)
	{
	printk("Error:cdev add faileed\n");
	return -1;
	}

	printk("Probe completed\n");
	return 0;
}

static const struct i2c_device_id eeprom_ids[] = {
	//{ 0x50, 0},
	{ devname, 0},
	{ }
};
MODULE_DEVICE_TABLE(i2c, eeprom_ids);

static struct i2c_driver eeprom_driver = {
	.driver = {
		.name = "eeprom",
		.owner = THIS_MODULE,
	},
	.probe = eeprom_probe,
	.remove = eeprom_remove,
	.id_table = eeprom_ids,
};

static int __init eeprom_init(void)
{
return i2c_add_driver(&eeprom_driver);
}

static void __exit eeprom_exit(void)
{
i2c_del_driver(&eeprom_driver);
}

module_init(eeprom_init);
module_exit(eeprom_exit);




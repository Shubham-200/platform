#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/bcd.h>
#include <asm/current.h>
#include <asm/highmem.h>
#include <linux/compiler.h>
#include <linux/errno.h>
#include <linux/export.h>
#include <linux/syscalls.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/mm_types.h>
#include <linux/mm.h>
#include <asm/page.h>
#include <linux/path.h>

#include <linux/i2c.h>
#include <linux/i2c-gpio.h>

#define PWR_MGMT_1   0x6B
#define SMPLRT_DIV   0x19
#define CONFIG       0x1A
#define FIFO_EN 	 0X23
#define GYRO_CONFIG  0x1B
#define ACCEL_CONFIG 0x1C
#define INT_ENABLE   0x38
#define ACCEL_XOUT_H 0x3B
#define ACCEL_YOUT_H 0x3D
#define ACCEL_ZOUT_H 0x3F
#define GYRO_XOUT_H  0x43
#define GYRO_YOUT_H  0x45
#define GYRO_ZOUT_H  0x47

static int mpu_probe(struct i2c_client *client, const struct i2c_device_id *id);
int mpu_remove(struct i2c_client * my_client);
int myopen(struct inode *inode, struct file *filep);
int myrelease(struct inode *in, struct file *fp);
static ssize_t myread(struct file *file_ptr, char __user *buff, size_t count, loff_t *pos);

MODULE_LICENSE("GPL");
MODULE_INFO(intree, "Y");
MODULE_AUTHOR("Shubham Talekar and Jyothi A");

static dev_t my_dev;
struct cdev *my_cdev;
static struct class *mychar_class;
static struct device *mychar_device;

struct file_operations fops={
    .owner = THIS_MODULE,
	.open = myopen,
	.read = myread,
	.release = myrelease,
};

static const struct i2c_device_id mpu_ids[] = {
	{ "mpu6050", 0 },
	{ }
};

MODULE_DEVICE_TABLE(i2c, mpu_ids);

static struct i2c_driver mpu_i2c_driver = {
    .driver = {
        .name   = "mpu6050",
        .owner  = THIS_MODULE,
    },
    .probe      = mpu_probe,
    .remove     = mpu_remove,
    .id_table   = mpu_ids,
};

struct my_i2c{ 								// i2c_data
	struct i2c_client *client;
	unsigned int addr;
	unsigned int buf[8];
}my_i2c;

int myopen(struct inode *inode, struct file *filep)
{
    printk(KERN_INFO "Device opened successfully\n");

    return 0;
}

int myrelease(struct inode *in, struct file *fp)
{
    printk(KERN_INFO "File realeased \n");

    return 0;
}

void selfTest(void)
{

	// Selftest MPU-6050
    unsigned char read_buf[10];
//  unsigned char read_buf1[10];
//  unsigned char read_buf2[10];
    unsigned int res[20];
    struct i2c_msg my_msg[2];
    unsigned char offset = 0x0D;
    int ret;


    printk(KERN_INFO "Test Case \n");
    printk(KERN_INFO "Reading the device\n");
    my_msg[0].addr = my_i2c.addr;
    my_msg[0].flags = 0;
    my_msg[0].buf = &offset;
    my_msg[0].len = 1;


    my_msg[1].addr = my_i2c.addr;
    //my_msg[1].flags = I2C_M_RD;
    my_msg[1].flags = 1;
    my_msg[1].buf = read_buf;
    my_msg[1].len = 3;

    printk(KERN_INFO "i2c adapter %x \n", (unsigned int) (my_i2c.client) -> adapter);

    mdelay(2);
    ret = i2c_transfer((my_i2c.client)->adapter, my_msg, 2);
    if(ret < 0)
    {
        printk(KERN_ERR "i2c_transfer failed, %d \n", ret);
        return ;
    }
	res[0] = bcd2bin(read_buf[0] & 0x1f);
    res[1] = bcd2bin(read_buf[1] & 0x1f);
    res[2] = bcd2bin(read_buf[2] & 0x1f);

    printk("------------------------------------------------\n");
    printk(KERN_INFO "Gyrometer reading on x-axis = %d\n", res[0]);
    printk(KERN_INFO "Gyrometer reading on y-axis = %d\n", res[1]);
    printk(KERN_INFO "Gyrometer reading on z-axis = %d\n", res[2]);

    res[3] = bcd2bin((read_buf[0] & 0xE0) >> 5);
    res[4] = bcd2bin((read_buf[1] & 0xE0) >> 5);
    res[5] = bcd2bin((read_buf[2] & 0xE0) >> 5);

    printk("-----------------------------------------------\n");
    printk(KERN_INFO "Accleration reading on x-axis = %d\n", res[3]);
    printk(KERN_INFO "Accleration reading on y-axis = %d\n", res[4]);
    printk(KERN_INFO "Accleration reading on z-axis = %d\n", res[5]);

}

static ssize_t myread(struct file *file_ptr, char __user *buf, size_t count, loff_t *pos)
{


	// Test Case for MPU-6050
//	unsigned char read_buf[10];
	unsigned char read_buf1[10];
	unsigned char read_buf2[10];
	unsigned int res[10];
	struct i2c_msg my_msg[2];
	unsigned char offset;
	int ret;

	//Actual reading of the MPU-6050
	printk("\n\n******************************************\n");
	printk(KERN_INFO "Actual reading of MPU-6050\n");
	
/*	ret = i2c_smbus_write_byte_data(my_i2c.client, PWR_MGMT_1, 0x80);
	printk(KERN_INFO "%d\n", ret);
	if(ret == 0)
	{
		printk(KERN_ALERT "PWR_MGMT_1 set\n");
	}
*/
    ret = i2c_smbus_write_byte_data(my_i2c.client, SMPLRT_DIV, 0x07);
    if(ret == 0)
    {
        printk(KERN_ALERT "SMPLRT_DIV set\n");

    }

	ret = i2c_smbus_write_byte_data(my_i2c.client, PWR_MGMT_1, 0x04);
	printk(KERN_INFO "%d\n", ret);
	if(ret == 0)
	{
		printk(KERN_ALERT "PWR_MGMT_1 set\n");
	}
/*	ret = i2c_smbus_write_byte_data(my_i2c.client, CONFIG, 0);
    if(ret ==  0)
    {
        printk(KERN_ALERT "CONFIG set\n");
    }

    ret = i2c_smbus_write_byte_data(my_i2c.client, FIFO_EN, 0X78);
    printk(KERN_INFO "%d\n", ret);

    if(ret == 0)
    {
        printk(KERN_ALERT "FIFO_EN set to 0x78 \n");
    }
*/

		offset = 0x3B;	

		my_msg[0].addr = my_i2c.addr;
		my_msg[0].flags = 0;
		my_msg[0].buf = &offset;
		my_msg[0].len = 1;

		my_msg[1].addr = my_i2c.addr;
		my_msg[1].flags =  1;
		//my_msg[1].flags =  I2C_M_RD;
		my_msg[1].buf = read_buf1;
		my_msg[1].len = 6;
	mdelay(2);
	ret = i2c_transfer((my_i2c.client)->adapter, my_msg, 2);
	if(ret < 0)
	{	
		printk(KERN_ERR "i2c_master_receive failed\n");
		return ret;
	}

	printk(KERN_INFO"3B -> %x\n", read_buf1[0]);
	printk(KERN_INFO"3C -> %x\n", read_buf1[1]);
	printk(KERN_INFO"3D -> %x\n", read_buf1[2]);
	printk(KERN_INFO"3E -> %x\n", read_buf1[3]);
	printk(KERN_INFO"3F -> %x\n", read_buf1[4]);
	printk(KERN_INFO"40 -> %x\n", read_buf1[5]);

	res[0] = bcd2bin(((read_buf1[0] << 8) | read_buf1[1])); 
	res[1] = bcd2bin(((read_buf1[2] << 8) | read_buf1[3]));
	res[2] = bcd2bin(((read_buf1[4] << 8) | read_buf1[5]));
	
	printk("------------------------------------------\n");
	printk("-----------Acceloremeter reading-----------\n");
	printk("X = %x\t Y = %x\t Z = %x\n", res[0], res[1], res[2]);
	
/*	ret = i2c_smbus_write_byte_data(my_i2c.client, PWR_MGMT_1, 0x80);
	printk(KERN_INFO "%d\n", ret);
	if(ret == 0)
	{
		printk(KERN_ALERT "PWR_MGMT_1 set\n");
	}

	ret = i2c_smbus_write_byte_data(my_i2c.client, SMPLRT_DIV, 7);
    if(ret == 0)
    {
        printk(KERN_ALERT "SMPLRT_DIV set\n");
    
    }   

    ret = i2c_smbus_write_byte_data(my_i2c.client, CONFIG, 0);
    if(ret ==  0)
    {
        printk(KERN_ALERT "CONFIG set\n");
    }

    ret = i2c_smbus_write_byte_data(my_i2c.client, FIFO_EN, 0X78);
    printk(KERN_INFO "%d\n", ret);
    if(ret == 0)
    {
        printk(KERN_ALERT "FIFO_EN set to 0x78 \n");
    }

*/	
	offset = 0x43;

	my_msg[0].addr = my_i2c.addr;
	my_msg[0].flags = 0;
	my_msg[0].buf = &offset;
	my_msg[0].len = 1;

	my_msg[1].addr = my_i2c.addr;
	my_msg[1].flags = 1;
	//my_msg[1].flags = I2C_M_RD;
	my_msg[1].buf = read_buf2;
	my_msg[1].len = 6;
	mdelay(2);
	ret = i2c_transfer((my_i2c.client)->adapter, my_msg, 2);
	if(ret < 0)
	{
		printk(KERN_ERR "i2c_master_receive failed\n");
		return ret;
	}

	printk(KERN_INFO"43 -> %x\n", read_buf2[0]);
	printk(KERN_INFO"44 -> %x\n", read_buf2[1]);
	printk(KERN_INFO"45 -> %x\n", read_buf2[2]);
	printk(KERN_INFO"46 -> %x\n", read_buf2[3]);
	printk(KERN_INFO"47 -> %x\n", read_buf2[4]);
	printk(KERN_INFO"48 -> %x\n", read_buf2[5]);

	res[3] = bcd2bin(((read_buf2[0] << 8) | read_buf2[1]));
	res[4] = bcd2bin(((read_buf2[2] << 8) | read_buf2[3]));
	res[5] = bcd2bin(((read_buf2[4] << 8) | read_buf2[5]));
	
	printk("-------------------------------------------\n");
	printk("-----------Gyrometer reading---------------\n");
	printk("X = %x\t Y = %x\t Z = %x\n", res[3], res[4], res[5]);
	

    if(copy_to_user(buf, res, 24))
        printk(KERN_INFO "Copy to user failed\n");
    else
        printk(KERN_INFO "Copy to user success\n");

		
	return 0;
}

static int __init my_init(void)
{
	int status;

	status = i2c_add_driver(&mpu_i2c_driver);

	if(status){
		printk(KERN_INFO "driver not added\n");
		return status;
	}	

	printk(KERN_INFO "driver added\n");

	return 0;	
}


static int mpu_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	int status;
//	unsigned char buf[4];
//	int ret;

	printk(KERN_INFO "detecting device\n");

	status = alloc_chrdev_region(&my_dev, 0, 1, "mpu6050");
	if(status < 0)
	{	
		printk(KERN_NOTICE "Device number allocation failed: %d\n", status);
		goto err;
	}
	printk(KERN_INFO "major number allocated, %d\n", MAJOR(my_dev));

	my_cdev = cdev_alloc();
	if(my_cdev == NULL){
		printk(KERN_ERR "cdev_alloc() failed\n");
	}

	cdev_init(my_cdev, &fops);
    my_cdev->owner = THIS_MODULE;

    status = cdev_add(my_cdev, my_dev, 1);
    if(status)
    {
        printk(KERN_ERR "cdev_add failed");
		goto err_cdev_add;
	}

    //create class and entry in sysfs

    mychar_class = class_create( THIS_MODULE, "mpu6050");
	if(IS_ERR(mychar_class))
    {
        printk(KERN_ERR "class_create failed");
        goto err_class_create;
    }

    //create mychar_device in sysfs and add entry in /dev

    mychar_device = device_create(mychar_class, NULL, my_dev, NULL, "mpu6050");
    if(IS_ERR(mychar_device))
    {
        printk(KERN_ERR "device_create failed");
        goto err_device_create;
    }

	status = i2c_check_functionality(client->adapter, I2C_FUNC_I2C & I2C_FUNC_SMBUS_WRITE_BYTE_DATA);

	if(!status)
	{
		printk(KERN_ALERT "Required I2C functionality not supported\n");
		return -ENODEV;
	}	

	printk(KERN_ALERT "Required I2C functionality done\n");

	my_i2c.client = client;
	my_i2c.addr = client -> addr;

	printk(KERN_INFO "client addr: %x\n", my_i2c.addr);

	selfTest();
	
	printk(KERN_INFO "probe done");
    return 0;

    err_device_create:
        class_destroy(mychar_class);

    err_class_create:
        cdev_del(my_cdev);

    err_cdev_add:
        kfree(my_cdev);

    err:
        return status;	
}
int mpu_remove(struct i2c_client * my_client)
{
	device_destroy(mychar_class, my_dev);
    class_destroy(mychar_class);
    cdev_del(my_cdev);
	unregister_chrdev_region(my_dev,1);
    printk(KERN_INFO "In the remove function\n");
    return 0;
}

static void __exit my_exit(void)
{
	printk(KERN_INFO "exiting device\n");
	i2c_del_driver(&mpu_i2c_driver);

	return ;
}

module_init(my_init);
module_exit(my_exit);

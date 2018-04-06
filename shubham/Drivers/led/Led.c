// A character device file for read and write operations

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <asm/delay.h>

#include <asm/current.h>
#include <asm/highmem.h>
#include <linux/compiler.h>
#include <linux/errno.h>
#include <linux/export.h>
#include <linux/syscalls.h>
#include <asm/cpufeature.h>

#include <linux/kernel.h>
#include <linux/mm_types.h>
#include <linux/mm.h>
#include <asm/page.h>
#include <linux/path.h>

MODULE_LICENSE("Dual BSD/GPL");

/** contents **/
#define FIRST_MINOR 0
#define NR_DEVS 1   //Number of device numbers

//static const char str[] = "Global edge software limited\n\0";
//static const ssize_t size_str = sizeof(str);

int myopen(struct inode *inode, struct file *filep);
int myrelease(struct inode *in, struct file *fp);
static ssize_t mywrite(struct file *file_ptr, char __user *buff, size_t count, loff_t *pos);

static int myinit(void);
static void myexit(void);

struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = myopen,
//	.read = myread,
	.write = mywrite,
	.release = myrelease,
};
/*
int check_region(unsigned long start, unsigned long n)
{
    return 0;
}
*/
char *devname;
int majno;
int port;
static dev_t mydev;
struct cdev *my_cdev;
static struct class *mychar_class;
static struct device *mychar_device;

int myopen(struct inode *inode, struct file *filep)
{
	printk(KERN_INFO "open successfully\n");
	
	return 0;
}

int myrelease(struct inode *in, struct file *fp)
{
	printk(KERN_INFO "File released\n");
	
	return 0;
}

static ssize_t mywrite(struct file *file_ptr, char __user *buff, size_t count, loff_t *pos)
{
    int i = 0;

    printk("func: %s\n", __FUNCTION__);

//  int data;

//  data = *buff;

    while(i < 10)
    {
        outb(*buff, 0x378);
        mdelay(500);
	outb(*buff, 0x378);
        mdelay(500);
        i++;
    }

    return count;
}


static int __init myinit(void)
{
	int ret = -ENODEV;
	int status;

	devname = "Led";

	printk(KERN_INFO "Initialising character device\n");
	
	status = alloc_chrdev_region(&mydev, FIRST_MINOR, NR_DEVS, devname);
	if(status < 0)
	{	
		printk(KERN_NOTICE "Device number allocation failed: %d\n", status);
		goto err;
	}
	printk(KERN_INFO "major number allocated: %d\n", MAJOR(mydev));
	my_cdev = cdev_alloc();
	if(my_cdev == NULL)
	{
		printk(KERN_ERR "cedv_alloc failed");
		goto err_cdev_alloc;
	}
	cdev_init(my_cdev, &fops);
	my_cdev->owner =  THIS_MODULE;
	status = cdev_add(my_cdev, mydev, NR_DEVS);
	if(status)
	{
		printk(KERN_ERR "cdev_add failed");
		goto err_cdev_add;
	}
	
	mychar_class = class_create(THIS_MODULE, devname);
	if(IS_ERR(mychar_class))
	{
		printk(KERN_ERR "class_create failed");
		goto err_class_create;
	}

	mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);
	if(IS_ERR(mychar_device))
	{
        	printk(KERN_ERR "device_create failed");
		goto err_device_create;
	}

	

//	port = check_region(0x378, 1);
/*
	if(port)
    {
        printk(KERN_ALERT "busy region");
        goto err;

    }
*/ 	
	request_region(0x378, 1, "parallel_port");
	return 0;

	err_device_create:
        	class_destroy(mychar_class);
	
	err_class_create:
		cdev_del(my_cdev);
	
	err_cdev_add:
		kfree(my_cdev);
	
	err_cdev_alloc:
		unregister_chrdev_region(mydev, NR_DEVS);
	
	err:
		return ret;

}

static void myexit(void)
{
    printk(KERN_INFO "exiting the character driver");
	release_region(0x378, 1);
    device_destroy(mychar_class, mydev);
    class_destroy(mychar_class);
    cdev_del(my_cdev);
    unregister_chrdev_region(mydev, NR_DEVS);
    return ;
}

module_init(myinit);
module_exit(myexit);

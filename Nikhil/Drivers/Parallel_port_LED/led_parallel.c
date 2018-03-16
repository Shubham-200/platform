#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/version.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/kernel.h>   //printk
#include <linux/slab.h>     //kmalloc
#include <linux/fs.h>
#include <linux/errno.h>    //error codes
#include <linux/types.h>    //size_t
#include <linux/fcntl.h>
#include <asm/uaccess.h>
#include <linux/uaccess.h>

#include <linux/ioctl.h>
#include <asm/delay.h>
#include <linux/delay.h>
#include <linux/ioport.h>

#define PORT_NO 0x378


//================IOCTL COMMANDS=============
#define BLINK	_IOW('a','a',int32_t*)
#define ON_ALL	_IOW('a','b',int32_t*)
#define OFF_ALL	_IOW('a','c',int32_t*)
#define A5A5	_IOW('a','d',int32_t*)
//==========================================

MODULE_LICENSE("GPL");

//==============Global variables=============
static dev_t dev;
static struct cdev c_dev;
static struct class *cls;

static int openCount = 0;
static int closeCount = 0;
static int major = 0;

//==========================================

//=================Function prototypes======
int LED_open(struct inode *inode, struct file *filp);
int LED_release(struct inode *inode, struct file *filp);
ssize_t LED_write(struct file *filp, const char *buf, size_t count, loff_t *offset);
static long LED_ioctl(struct file *file, unsigned int cmd, unsigned int arg);
static void __exit LED_exit(void);
static int __init LED_init(void);
//==========================================

struct semaphore LED_sem;

DEFINE_SEMAPHORE(LED_sem);	


struct file_operations LED_fops = {
  .owner = THIS_MODULE,
  .open = LED_open,
  .release = LED_release,
  .write = LED_write,
  .unlocked_ioctl = LED_ioctl
};


int LED_open( struct inode *inode, struct file *filp) {

    openCount++;
    printk(KERN_INFO "Opening \"LED\" %d times\n", openCount);
    return 0;

}

int LED_release( struct inode *inode, struct file *filp) {
    closeCount++;
    printk(KERN_INFO "Closing \"LED\" %d times\n",closeCount);
    return 0;
}

ssize_t LED_write(struct file *filp, const char __user *buf, size_t count, loff_t *offset)
{
	printk("writning...\n");
	down(&LED_sem);
	outb(*buf, 0x378);
	up(&LED_sem);
	return count;
}

 
static long LED_ioctl(struct file *file, unsigned int cmd, unsigned int arg)
{
	char count = *(int*)arg; 
	unsigned char data;

	down(&LED_sem);
         switch(cmd) {
                case BLINK:
                        printk("IOCTL: Running blink \n");
                        while( count != 0) {
                            data = 0xff;
                            outb(data, 0x378);
                            mdelay(500);
                            data = 0x00;
                            outb(data, 0x378);
                            mdelay(500);
                            count--;
                        }
                        break;
                case A5A5:
                        printk("IOCTL: Running A5A5\n");
                        while( count != 0) {
                            data = 0xAA;
                            outb(data, 0x378);
                            mdelay(500);
                            data = 0x55;
                            outb(data, 0x378);
                            mdelay(500);
                            count--;
                        }
                        data = 0x00;
                        outb(data, 0x378);
                        break;
                case ON_ALL:
                        data = 0xff;
                        outb(data, 0x378);
                        break;
                case OFF_ALL:
                        data = 0x00;
                        outb(data, 0x378);
                        break;

        }
	
	up(&LED_sem);
        return 0;
}
 

static int __init LED_init( void ) {
    int res;
    struct device *dev_res;
	/* Registering port */

/*	port = check_region(PORT_NO, 1);
	if (port) { 

	    printk("<1>parlelport: cannot reserve 0x378\n"); 

	    res = port; 

    	goto fail;

	} 
*/

 	 request_region(PORT_NO, 1, "parlelport");

    if( (res = alloc_chrdev_region(&dev, 0, 1, "parallel_driver")) < 0) {
        printk(KERN_INFO "simple_driver error in alloc_char_region\n");
        return res;
    }
	
	major = MAJOR(dev);
	
    cdev_init(&c_dev, &LED_fops);
    if( (res = cdev_add(&c_dev, dev, 1)) < 0) {
        unregister_chrdev_region(dev, 1);
        return (res);
    }

    if ( IS_ERR( cls = class_create(THIS_MODULE, "chardev"))) {
        cdev_del(&c_dev);
        unregister_chrdev_region(dev,1);
        return PTR_ERR(cls);
    }

    if( IS_ERR(dev_res = device_create(cls, NULL, dev, NULL, "LED_driver"))) {
        class_destroy(cls);
        cdev_del(&c_dev);
        unregister_chrdev_region(dev,1);
        return PTR_ERR(dev_res);
    }

    printk(KERN_INFO "LED registering module\n");
  	
	return 0;
/*
	fail:
		return res;
*/
}

static void __exit LED_exit( void ) {



 	release_region(PORT_NO, 1);
    device_destroy(cls, dev);
    class_destroy(cls);
    cdev_del(&c_dev);
    unregister_chrdev_region(dev, 1);

    printk(KERN_INFO "LED module unregistered\n");

}



module_init( LED_init);
module_exit( LED_exit);




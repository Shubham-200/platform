/*
 * plp_kmem.c - Kernel memory allocation examples.
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/vmalloc.h>

#include <linux/fs.h>
#include <linux/major.h>
#include <linux/blkdev.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>

#include <linux/device.h>
#include <linux/slab.h>

#define PLP_KMEM_BUFSIZE (1024*1024) /*1MB internel buffer*/

/* global variables */
static char *plp_kmem_buffer;

static struct class *plp_kmem_class; /* pretend /sys/class */
static dev_t plp_kmem_dev; 			/*dynamically assigned char device*/
static struct cdev *plp_kmem_cdev; 	/*dynamically allocated at runtime*/

/*function prototypes*/
static int __init plp_kmem_init(void);
static void __exit plp_kmem_exit(void);

static int plp_kmem_open(struct inode *inode, struct file *file);
static int plp_kmem_release(struct inode *inode, struct file *file);
static ssize_t plp_kmem_read(struct file *file, char __user *buf, size_t count, loff_t *ppos);
static ssize_t plp_kmem_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos);

/*file operations */
static struct file_operations plp_kmem_fops = {
	.read = plp_kmem_read,
	.write = plp_kmem_write,
	.open = plp_kmem_open,
	.release = plp_kmem_release,
	.owner = THIS_MODULE,
};

/*
 * plp_kmem_open: Open the kmem device
 */
static int plp_kmem_open(struct inode *inode, struct file *file)
{

	#ifdef PLP_DEBUG
		printk(KERN_DEBUG "plp_kmem:opened device.\n");
	#endif

	return 0;
}

/*
 *plp_kmem_release: close the kmem device.
 */
static int plp_kmem_release(struct inode *inode, struct file *file)
{
	#ifdef PLP_DEBUG
		printk(KERN_DEBUG "plp_kmem:device closed.\n");
	#endif
	
	return 0;
}

/*
 *plp_kmem_read:Read from the device.
 */
static ssize_t plp_kmem_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
	size_t bytes = count;
	loff_t fpos = *ppos;
	char *data;

	if(fpos >= PLP_KMEM_BUFSIZE)
		return 0;

	if((fpos + bytes) >= PLP_KMEM_BUFSIZE)
		bytes = PLP_KMEM_BUFSIZE - fpos;

	if(0 == (data = kmalloc(bytes, GFP_KERNEL)))
		return -ENOMEM;

	#ifdef PLP_DEBUG
		printk(KERN_DEBUG "plp_kmem: read %d bytes from device,offset %d.\n",bytes, (int)fpos);
	#endif

	memcpy(data, plp_kmem_buffer+fpos,bytes);

	if(copy_to_user((void __user *)buf, data, bytes)) {
		printk(KERN_ERR "plp_kmem: cannot write data.\n");
		kfree(data);
		return -EFAULT;
	}

	*ppos = fpos + bytes;

	kfree(data);
	return bytes;
}

/*
 *plp_kmem_write: Write to the device.
 */
static ssize_t plp_kmem_write(struct file *file,const char __user *buf, size_t count, loff_t *ppos)
{
	size_t bytes = count;
	loff_t fpos = *ppos;
	char *data;

	if(fpos >= PLP_KMEM_BUFSIZE)
		return -ENOSPC;
	
	if((fpos + bytes) >= PLP_KMEM_BUFSIZE)
		bytes = PLP_KMEM_BUFSIZE - fpos;
	
	if(0 == (data = kmalloc(bytes, GFP_KERNEL)))
		return -ENOMEM;

	if(copy_from_user((void *)data, (const void __user*)buf, bytes)){
		printk(KERN_ERR "plp_kmem:cannot read data\n");
		kfree(data);
		return -EFAULT;
	}
	
	#ifdef PLP_DEBUG
		printk(KERN_DEBUG "plp_kmem: write %d bytes to device, offset %d.\n",bytes, (int) fpos);
	#endif

	memcpy(plp_kmem_buffer+fpos,data, bytes);

	*ppos = fpos+bytes;
	
	kfree(data);
	return bytes;
}

/*
 *plp_kmem_init: load the kernel module into memory
 */
static int __init plp_kmem_init(void)
{
	printk(KERN_INFO "plp_kmem: Allocating %d bytes of internal buffer. \n",PLP_KMEM_BUFSIZE);
	if(NULL == (plp_kmem_buffer = vmalloc(PLP_KMEM_BUFSIZE))){
		printk(KERN_ERR "plp_kmem: cannot allocate memory!\n");
		goto error;
	}

	memset((void *)plp_kmem_buffer, 0, PLP_KMEM_BUFSIZE);

	if(alloc_chrdev_region(&plp_kmem_dev, 0, 1, "plp_kmem"))
		goto error;

	if(0 == (plp_kmem_cdev = cdev_alloc()))
		goto error;

	kobject_set_name(&plp_kmem_cdev->kobj, "plp_kmem_cdev");
	plp_kmem_cdev -> ops = &plp_kmem_fops; /*file up fops */
	if(cdev_add(plp_kmem_cdev, plp_kmem_dev, 1)){
		kobject_put(&plp_kmem_cdev->kobj);
		unregister_chrdev_region(plp_kmem_dev, 1);
		goto error;
	}

	plp_kmem_class = class_create(THIS_MODULE, "plp_kmem");
	if(IS_ERR(plp_kmem_class)){
		printk(KERN_ERR"plp_kmem: error creating class.\n");
		cdev_del(plp_kmem_cdev);
		unregister_chrdev_region(plp_kmem_dev, 1);
		goto error;
	}
	device_create(plp_kmem_class, NULL, plp_kmem_dev, NULL, "plp_kmem");

	printk(KERN_INFO "plp_kmem:loaded.\n");

	return 0;

	error:
		printk(KERN_ERR"plp_kmem: cannot register device.\n");
	return 1;
}

/*
 *plp_kmem_exit:unload the kernel module from memory
 */
static void __exit plp_kmem_exit(void)
{
	device_destroy(plp_kmem_class, plp_kmem_dev);
	class_destroy(plp_kmem_class);
	cdev_del(plp_kmem_cdev);
	unregister_chrdev_region(plp_kmem_dev, 1);

	vfree(plp_kmem_buffer);

	printk(KERN_INFO "plp_kmem: unloading.\n");
}

/*declare init/exit functions here */
module_init(plp_kmem_init);
module_exit(plp_kmem_exit);

/*define module meta data */
MODULE_AUTHOR("Akshata Mukund Shetty");
MODULE_DESCRIPTION("Demonstrate kernel memory allocation");

MODULE_ALIAS("memory_allocation");
MODULE_LICENSE("GPL");
MODULE_VERSION("0:1.0");

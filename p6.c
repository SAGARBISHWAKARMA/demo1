#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/device.h>
#include<linux/cdev.h>
#include<linux/delay.h>
#include<linux/fs.h>

MODULE_LICENSE("GPL");

int count=1;
int minor_number=0;
char *device_name = "mychardev556";
static struct class *class;
static struct device  *device;
dev_t devicenumber;


static int device_open(struct inode *inode, struct file *file)
{
pr_info("%s\n",__func__);
return 0;

}
static int device_release(struct inode *inode, struct file *file)
{
pr_info("%s\n",__func__);
return 0;

}

struct ssize_t device_read(struct file *file, char __user *user_buffer,size_t count, loff_t *offset)
{
pr_info("%s\n",__func__);
return 0;
}

struct ssize_t device_write(struct file *file, const char __user *user_buffer,size_t count, loff_t *offset)
{
pr_info("%s\n",__func__);
return count;
}

struct file_operation device_fops= {
.read= device_read,
.write= device_write,
.open= device_open,
.release =device_release
};



static int __init  start()
{

class = class_create(THIS_MODULE, "SAGAR2");

if(!alloc_chrdev_region(&devicenumber,minor_number,count,device_name))
{
printk("device number register \n");
printk("major number receive %d\n",MAJOR(devicenumber));
device= device_create(class,NULL,devicenumber,NULL,"device_name");
//device2= device_create(class,NULL,dev2,NULL,"mydevice%d",2);

printk("Device Create\n");
}
else
printk("device registrar=tion is fail\n");
return 0;
}

static void __exit stop(void)
{
unregister_chrdev_region(devicenumber,count);

//device_destroy(class,dev1);
device_destroy(class,devicenumber);

class_destroy(class);

printk("let device destroy");
}

module_init(start);
module_exit(stop);



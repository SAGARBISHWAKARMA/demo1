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
char *device_name = "mychardev55";
static struct class *class;
static struct device  *device;
dev_t devicenumber;

static int __init  start(void)
{

//dev1= MKDEV(200,1);
//dev2= MKDEV(200,2);

class = class_create(THIS_MODULE, "SAGAR1");

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



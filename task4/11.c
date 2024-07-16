#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/printk.h>
#include<linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR ("BISHWAKARMA");
MODULE_DESCRIPTION("DISPLAY DATA IN TERMAL");


static int __init start(void)
{

printk(KERN_CONT "this is to printing the display the 11 question\n" );

return 0;
}

static void __exit stop(void)
{
printk(KERN_CONT "THIS IS TO END QUESTION 11\n");


}

module_init(start);
module_exit(stop);

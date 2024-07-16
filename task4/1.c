#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/printk.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("1_BBB");
MODULE_DESCRIPTION("THIS IS FOR BBB");

int start(void)
{

	printk(KERN_INFO"THIS IS TO START BBB\n");
	return 0;
}


void stop(void)
{
	printk(KERN_INFO"let end BBB\n");

}

module_init(start);
module_exit(stop);

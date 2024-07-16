#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/printk.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BISHWAKARMA");
MODULE_DESCRIPTION("THIS IS A 3 PROGRAM FROM TASK3");

int start(void)
{

	printk(KERN_EMERG "EMERGENCY MESSAGE\n");
	printk(KERN_ALERT "ALERT MESSAGE\n");
	printk(KERN_CRIT"critical message\n");
	printk(KERN_ERR" error message\n");
	printk(KERN_WARNING"warning message");
	printk(KERN_NOTICE"notice a message\n");
	printk(KERN_DEBUG"debug the message\n");

	return 0;

}

void stop(void)
{
printk(KERN_INFO"info: goodbye from the question 3\n");

}

module_init(start);
module_exit(stop);

#include<linux/module.h>
#include<linux/printk.h>

int init_module(void)
{
	pr_info("hello world\n");
	return 0;
}

void cleanup_module(void)
{
	pr_info("clean up all");
}

MODULE_LICENSE("MESSAGE GPL");

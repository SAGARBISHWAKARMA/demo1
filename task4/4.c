#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Your Description");

int start(void)
{
    pr_info("Start function\n"); 

    panic("panic the kernel\n");
    return 0;

}

void stop(void)
{
    pr_info("Stop function\n");

}

module_init(start);
module_exit(stop);


#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bishwakarma");
MODULE_DESCRIPTION("A simple example Linux module.");

static int __init start(void) {
    printk(KERN_INFO "Hello, World!\n");
    return 0;
}

static void __exit stop(void) {
    printk(KERN_INFO "Goodbye, World!\n");
}

module_init(start);
module_exit(stop);


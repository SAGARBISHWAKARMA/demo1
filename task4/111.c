#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/tty.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bishwakarma");
MODULE_DESCRIPTION("LKM to print output directly to terminal");


void write_to_tty(const char* message)
{
    struct tty_struct *tty;

    tty = get_current_tty();
    if (tty != NULL) {
        tty->ops->write(tty, message, strlen(message));
        tty->ops->write(tty, "\015\012", 2); // New line
    } else {
        printk(KERN_ALERT "Failed to get TTY struct\n");
    }
}


struct tty_struct* get_current_tty(void)
{
    struct tty_struct *tty;
    struct task_struct *task = current;

    tty = task->signal->tty;
    if (!tty) {
        printk(KERN_ALERT "No TTY found for current task\n");
    }
    return tty;
}

static int __init start(void)
{
    printk(KERN_INFO "Loading tty_print_lkm module\n");
    write_to_tty("Hello, this is a message from the kernel module!");
    return 0;
}

static void __exit stop(void)
{
    printk(KERN_INFO "Unloading tty_print_lkm module\n");
    write_to_tty("Goodbye from the kernel module!");
}

module_init(start);
module_exit(stop);

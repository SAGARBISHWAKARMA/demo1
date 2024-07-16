#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/tty.h>
#include <linux/tty_driver.h>

static struct tty_struct *tty;

static int __init tty_output_init(void)
{
    printk(KERN_INFO "Hello TTY Module: Initializing\n");

    tty = get_current_tty();
    if (!tty) {
        printk(KERN_ERR "Hello TTY Module: Unable to get current TTY\n");
        return -ENODEV;
    }

    printk(KERN_INFO "Hello TTY Module: Got current TTY\n");

    if (tty->ops->write) {
        tty->ops->write(tty, "Hello, world!\n", strlen("Hello, world!\n"));
    }

    printk(KERN_INFO "Hello TTY Module: Message sent to TTY\n");

    return 0;
}

static void __exit tty_output_exit(void)
{
    printk(KERN_INFO "Hello TTY Module: Exiting\n");

    if (tty->ops->write) {
        tty->ops->write(tty, "Goodbye, world!\n", strlen("Goodbye, world!\n"));
    }

    printk(KERN_INFO "Hello TTY Module: Goodbye message sent to TTY\n");
}

module_init(tty_output_init);
module_exit(tty_output_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Kernel module to print output to terminal");

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <asm/processor.h>
#include <asm/paravirt.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Print x86_64 Control Registers and Check PAE");

// Use the existing definitions for read_cr0 and read_cr2
// Define inline functions for read_cr3, read_cr4, and read_cr8
static unsigned long read_cr3(void)
{
    unsigned long val;
    asm volatile("mov %%cr3, %0" : "=r"(val));
    return val;
}

static unsigned long read_cr4(void)
{
    unsigned long val;
    asm volatile("mov %%cr4, %0" : "=r"(val));
    return val;
}

static unsigned long read_cr8(void)
{
    unsigned long val;
    asm volatile("mov %%cr8, %0" : "=r"(val));
    return val;
}

static int __init start(void)
{
    unsigned long cr0 = read_cr0();
    unsigned long cr2 = read_cr2();
    unsigned long cr3 = read_cr3();
    unsigned long cr4 = read_cr4();
    unsigned long cr8 = read_cr8();

    printk(KERN_INFO "CR0: 0x%lx\n", cr0);
    printk(KERN_INFO "CR2: 0x%lx\n", cr2);
    printk(KERN_INFO "CR3: 0x%lx\n", cr3);
    printk(KERN_INFO "CR4: 0x%lx\n", cr4);
    printk(KERN_INFO "CR8: 0x%lx\n", cr8);

    // Check if PAE is enabled (bit 5 of CR4)
    if (cr4 & (1 << 5)) {
        printk(KERN_INFO "PAE (Physical Address Extension) is enabled.\n");
    } else {
        printk(KERN_INFO "PAE (Physical Address Extension) is not enabled.\n");
    }

    return 0;
}

static void __exit stop(void)
{
    printk(KERN_INFO "Module removed\n");
}

module_init(start);
module_exit(stop);


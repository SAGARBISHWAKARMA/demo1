#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/printk.h>
#include<linux/utsname.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bishwakarma");
MODULE_DESCRIPTION("this is a question 2 from task 3");

#define EMAIL_ID "sagarbishwakarma"

static int start(void)
{
struct new_utsname *uts = utsname();
    
    if (uts)
    {
        printk(KERN_INFO "Hostname: %s\n", uts->nodename);
        printk(KERN_INFO "Email ID: %s\n", EMAIL_ID);
    }
    
    return 0;

}

static void stop(void)
{
 printk(KERN_INFO "Goodbye from the hostname_email_lkm module\n");
}


module_init(start);
module_exit(stop);

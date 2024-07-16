#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h> 
#include <linux/sched/signal.h> 

MODULE_LICENSE("GPL");
MODULE_AUTHOR("sagar");
MODULE_DESCRIPTION("Get the current task");

static int start(void)
{
    struct task_struct *task;
    task = current;

    printk(KERN_INFO "Current task PID: %d\n", task->pid);
    printk(KERN_INFO "Current task name: %s\n", task->comm);

    return 0;
}

static void stop(void)
{
    printk(KERN_INFO "Question 14 is completed \n");
}

module_init(start);
module_exit(stop);


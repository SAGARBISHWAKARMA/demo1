#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/time.h>
#include<linux/init.h>
#include<linux/timekeeping.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("BISHWAKARMA");
MODULE_DESCRIPTION("THIS IS TO DISPLAY TIME ");


static int __init start(void)
{
	struct timespec64  ts;
	struct tm tm;

	ktime_get_real_ts64(&ts);
	time64_to_tm(ts.tv_sec, 0, &tm);

printk(KERN_INFO"this is to display the time data in a display\n");
printk(KERN_INFO "current time %4ld %2d %2d %2d %2d %2d\n",tm.tm_year+1900 ,tm.tm_mon +1, tm.tm_mday,tm.tm_hour, tm.tm_min, tm.tm_sec);

return 0;
}

static void __exit stop(void)
{

printk(KERN_INFO "this is to stop 14th question\n");
}

module_init(start);
module_exit(stop);

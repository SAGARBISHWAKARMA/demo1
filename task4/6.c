#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include<linux/errno.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("SAGAR");
MODULE_DESCRIPTION("PRINT OUT THE NUMBER");

#define size 10

static int arr[size];
static int arr_argc = 0;

module_param_array(arr, int, &arr_argc, 0664);
MODULE_PARM_DESC(arr, "An array of integers");

static int start(void)
{
	int i;

	if (arr_argc != size) {
		printk(KERN_ERR "Expected %d integers, but got %d\n",size, arr_argc);
		return -EINVAL;
	}

	for (i = 0; i < size; i++) {
		printk(KERN_INFO "VALUE OF I IS = %d in array is %d\n", i, arr[i]);
	}

	return 0;
}

static void stop(void)
{
	printk(KERN_INFO "Let end 6th programming\n");
}

module_init(start);
module_exit(stop);


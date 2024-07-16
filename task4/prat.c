#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/errno.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SAGAR");
MODULE_DESCRIPTION("PRINT OUT THE NUMBER");

#define SIZE 10
static int arr[SIZE];
static int arr_argc = 0;

module_param_array(arr, int, &arr_argc, 0664);
MODULE_PARM_DESC(arr, "An array of integers");

static int start(void)
{
    int i, j;

    // Print the initial array
    for (i = 0; i < SIZE; i++) {
        printk(KERN_INFO "Initial: VALUE OF I IS = %d in array is %d\n", i, arr[i]);
    }

    // Bubble sort algorithm
    for (i = 0; i < SIZE - 1; i++) {
        for (j = i + 1; j < SIZE; j++) {  // Fixed the inner loop condition
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Print the sorted array
    for (i = 0; i < SIZE; i++) {
        printk(KERN_INFO "Sorted: VALUE OF I IS = %d in array is %d\n", i, arr[i]);
    }
    
    return 0;
}

static void stop(void)
{
    printk(KERN_INFO "Let end 7th programming\n");
}

module_init(start);
module_exit(stop);


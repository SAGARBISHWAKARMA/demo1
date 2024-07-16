
#include <linux/module.h> 
#include <linux/printk.h> 
#include <linux/init.h> 
#include <linux/minmax.h> 
#include <linux/moduleparam.h> 
#include <linux/version.h> 
 
MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("YEPURI SIDDU"); 
MODULE_DESCRIPTION("Min and Max of 3 numbers"); 
static int a = 1; 
static int b = 2; 
static int c = 3; 
 
module_param(a, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP); 
MODULE_PARM_DESC(a, "A integer value"); 
module_param(b, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP); 
MODULE_PARM_DESC(b, "A integer value"); 
module_param(c, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP); 
MODULE_PARM_DESC(c, "A integer value"); 
 
static int __init start_code(void) 
{ 
int value=LINUX_VERSION_CODE; 
pr_info("Linux version CODE:%d",LINUX_VERSION_CODE); 
        pr_info("version:%d.%d.%d\n",value>>16,(value%(1<<16))>>8,(value%(1<<16)%(1<<8))); 
pr_info("Greatest and smallest of 3 values code started "); 
pr_info("Minimum value of 3:%d\n",min3(a,b,c)); 
pr_info("Maximum value of 3:%d\n",max3(a,b,c)); 
return 0; 
} 
 
static void __exit stop_code(void) 
{ 
pr_info("Thank you for adding module\n"); 
}  
 
module_init(start_code); 
module_exit(stop_code) 
 

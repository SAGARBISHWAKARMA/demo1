#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/random.h>
#include <linux/time.h>
#include <linux/slab.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BISHWAKARMA");
MODULE_DESCRIPTION("ADD A NODE AND PRINT THAT DATA");

typedef struct node {
    int data;
    int sqrt;
    struct node *next;
} node;

static int number = 5;
module_param(number, int, 0);
MODULE_PARM_DESC(number, "Number of nodes to be added");

static node *headptr = NULL;

void addNode(node **);
void printData(node *);
void reverseData(node *);
void deleteNode(node **);

static int __init start(void) {
    int i = 0;

    for (i = 0; i < number; i++) {
        addNode(&headptr);
    }
    printData(headptr);

    return 0;
}

static void __exit stop(void) {
    printk(KERN_INFO "Removing all allocated data\n");
    deleteNode(&headptr);
}

void addNode(node **ptr) {
    int random;
    node *new_node = kmalloc(sizeof(node), GFP_KERNEL);

    if (!new_node) {
        printk(KERN_ERR "Memory allocation failed\n");
        return;
    }

    get_random_bytes(&random, sizeof(char));

    if(random < 0)
    {
	random=-random;
    }

    new_node->data = (random);

    new_node->next = *ptr;
    *ptr = new_node;
}

void printData(node *ptr) {
    if (ptr == NULL) {
        printk(KERN_INFO "Node list is empty\n");
        return;
    }

    while (ptr) {
        printk(KERN_INFO "Value of data in a node is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void deleteNode(node **ptr) {
    printk(KERN_INFO "Deleting all data\n");

    if (*ptr == NULL) {
        printk(KERN_INFO "Nothing left to delete\n");
        return;
    }

    node *delete;

    while (*ptr) {
        delete = *ptr;
        *ptr = (*ptr)->next;
        kfree(delete);
    }
}

void reverseData(node *ptr) {
    if (ptr == NULL) {
        printk(KERN_INFO "Node list is empty, nothing to reverse\n");
        return;
    }

    if (ptr->next != NULL) {
        reverseData(ptr->next);
    }
    printk(KERN_INFO "Value of node data is %d\n", ptr->data);
}

module_init(start);
module_exit(stop);


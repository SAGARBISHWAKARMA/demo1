#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/random.h>
#include <linux/slab.h>
#include <linux/ktime.h>
#include <linux/math64.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bishwakarma");
MODULE_DESCRIPTION("A module to create and manipulate a kernel linked list with timing");


static int num_nodes = 5;
module_param(num_nodes, int, 0);
MODULE_PARM_DESC(num_nodes, "Number of nodes to add to the linked list and to get a time");

typedef struct node {
    int num;
    int sqrt;
    struct list_head list;
} node_t;

LIST_HEAD(linked_list);

static void add_node(int num)
{
    node_t *new_node;
    new_node = kmalloc(sizeof(node_t), GFP_KERNEL);

    if (new_node==NULL)
    {
        printk(KERN_ERR "Failed to allocate memory for new node\n");
        return;
    }

    new_node->num = num;
    new_node->sqrt = int_sqrt(num);
    INIT_LIST_HEAD(&new_node->list);
    list_add_tail(&new_node->list, &linked_list);
}

static void print_list_reverse(void) {
    node_t *entry;
    struct list_head *pos;

    printk(KERN_INFO "Printing linked list in reverse order:\n");

    list_for_each_prev(pos, &linked_list) 
    {
        entry = list_entry(pos, node_t, list);
        printk(KERN_INFO "Node: num = %d, sqrt = %d\n", entry->num, entry->sqrt);
    }
}

static void delete_list(void) 
{
    node_t *entry, *next;

    list_for_each_entry_safe(entry, next, &linked_list, list) 
    {
        list_del(&entry->list);
        kfree(entry);
    }
    printk(KERN_INFO "All nodes have been deleted and memory freed\n");
}

static int __init start(void) {
    int i, num;
    ktime_t start, end;
    s64 time_ns;

    printk(KERN_INFO "Initializing linked list module\n");

    start = ktime_get();


    for (i = 0; i < num_nodes; i++)
    {
        get_random_bytes(&num, sizeof(char));
        num = num < 0 ? -num : num;
        add_node(num);
    }

    end = ktime_get();

    time_ns = ktime_to_ns(ktime_sub(end, start));

    printk(KERN_INFO "Time taken to insert %d nodes: %lld ns\n", num_nodes, time_ns);

    print_list_reverse();

    return 0;
}

static void __exit stop(void) {
    printk(KERN_INFO "Exiting linked list module\n");
    delete_list();
}

module_init(start);
module_exit(stop);


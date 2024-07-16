#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/random.h>
#include<linux/time.h>
#include<linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BISHWAKARMA");
MODULE_DESCRIPTION("ADD A NODE AND PRINT THAT DATA");


typedef struct node{
	int data;
	int sqrt;
	struct node *next;
}node; 

static int number =5;
module_param(number,int ,0);
MODULE_PARM_DESC(NUMBER,"here are number of nodes decided");

void addNode(node **);
void printData(node *);
void reverseData(node *);

static int start(void)
{
	int i=0;
	node *headptr=0;

	for(i=0;i<number;i++)
	{
		addNode(&headptr);
	}
	printData(headptr);
	reverseData(headptr);
	return 0;
}

static void stop(void)
{
	printk(KERN_INFO"at remove all the data which are allocate\n");
}

void addNode(node **ptr)
{
	int random;
	node *new=kmalloc(sizeof(node),GFP_KERNEL);

	get_random_bytes(&random,sizeof(char));
	new->data=random;

	new->next=*ptr;
	*ptr=new;
}

void printData(node *ptr)
{
	if(ptr==NULL)
	{
		printk(KERN_INFO"THIS SHOWING THAT NODE IS EMPTY\n");
	}

	while(ptr)
	{
		printk(KERN_INFO "value of data in a node is %d\n",ptr->data);
		ptr=ptr->next;
	}
}

void deleteNode(node **ptr)
{
	printk(KERN_INFO "lets delete all data\n");
	
	if(*ptr==NULL)
	{
		printk(KERN_INFO"NOTHING LEFT TO DELETE\n");
		return ;
	}
	node * delete;

	while(*ptr)
	{
	delete=*ptr;
	*ptr=(*ptr)->next;
	kfree(delete);
	
	}
}

void reverseData(node *ptr)
{

if(ptr == NULL)
{
printk(KERN_INFO " NODE IS EMPTY AND NOTHING TO REVERSE");
return;
}

  if (ptr->next != NULL)
    {
        reverseData(ptr->next);
    }
printk(KERN_INFO "VALUE OF a noda data id %d\n",ptr->data);


}


module_init(start);
module_exit(stop);

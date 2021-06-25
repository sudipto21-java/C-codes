#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int val)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	
	nn->data=val;
	nn->link=NULL;
	
	if(front==NULL && rear==NULL)
		front=rear=nn;	
	else
	{
		rear->link=nn;
		rear=nn;	
	}
}

void dequeue()
{
	struct node *temp=front;
	
	if(front==rear)
		front=rear=NULL;
	else
		front=front->link;
		
	free(temp);
}

void print_queue(struct node *head)
{
	if(head==NULL)
		printf("queue is empty");
	else
	{
		while(head!=NULL)
		{
			printf("%d\n",head->data);
			head=head->link;
		}
	}
}

int main()
{
	int i,n,x;
	
	printf("enter number of elements:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&x);
		enqueue(x);
	}
	
	print_queue(front);
	
	dequeue();
	dequeue();
	
	printf("after deletion queue is\n");
	
	print_queue(front);
	
	return 0;
}


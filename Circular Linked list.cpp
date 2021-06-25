#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *head=NULL;

void create_node(int val)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	struct node *temp;
	
	nn->data=val;
	nn->link=NULL;
	
	if(head==NULL)
	{
		head=nn;
		nn->link=head;
	}
	else
	{
		temp=head;
		while(temp->link!=head)
		{
			temp=temp->link;
		}
		
		nn->link=head;
		temp->link=nn;
	}
}

void print(struct node *strt)
{
	struct node *temp=strt;
	
	if(strt==NULL)
		printf("list is empty");
	else
	{
		while(strt->link!=temp)
		{
			printf("%d\n",strt->data);
			strt=strt->link;
		}
		printf("%d\n",strt->data);
	}
}

int main()
{
	int i,n,x;
	printf("enter number of elements:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter number:");
		scanf("%d",&x);
		create_node(x);
	}
	
	print(head);
	
	return 0;
}

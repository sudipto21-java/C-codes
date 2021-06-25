#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node *fwd,*bwd;
};

struct node *head=NULL;

void create_node(int val)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	struct node *temp;
	
	nn->data=val;
	nn->fwd=NULL;
	nn->bwd=NULL;
	
	if(head==NULL)
		head=nn;
	else
	{
		temp=head;
		while(temp->fwd!=NULL)
		{
			temp=temp->fwd;
		}
		temp->fwd=nn;
		nn->bwd=temp;
	}
}

void print_list(struct node *strt)
{
	if(strt==NULL)
		printf("list is empty\n");
	else
	{
		while(strt!=NULL)
		{
			printf("%d\n",strt->data);
			strt=strt->fwd;
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
		create_node(x);
	}
	
	print_list(head);
	
	return 0;
}

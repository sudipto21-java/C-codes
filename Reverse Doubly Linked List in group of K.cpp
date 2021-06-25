#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *fwd, *bwd;
};

struct node *head=NULL;

void new_node(int data)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	
	nn->data=data;
	nn->bwd=nn->fwd=NULL;
	
	if(head==NULL)
		head=nn;
	else
	{
		struct node *tempf, *tempb;
		tempb=tempf=head;
		
		while(tempf->fwd!=NULL)
		{
			tempb=tempf;
			tempf=tempf->fwd;
		}
		
		tempf->fwd=nn;
		tempf->bwd=tempb;
	}
}

void reverse_in_pair(struct node *start)
{
//	printf("start\n");
	if(start==NULL)
		return;
	
	struct node *temp=start;
	int val;
	
	while(start!=NULL && temp!=NULL)
	{
//		printf("while\n");
//		printf("%d\n",temp->data);
		start=start->fwd;
//		printf("%d\n",start->data);
		val=temp->data;
		temp->data=start->data;
//		printf("%d\n",temp->data);
		start->data=val;
//		printf("%d\n",start->data);
		if(temp->fwd==start)
		{
//			printf("if\n");
			start=start->fwd;
			temp=start->fwd;
		}
	}
}

void print_list(struct node *start)
{
	if(start==NULL)
		printf("list is empty");
	else
	{
		while(start!=NULL)
		{
			printf("%d\t",start->data);
			start=start->fwd;
		}
	}
}

int main()
{
	int n,i,x,k;
	
	printf("enter count of nodes:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&x);
		new_node(x);
	}
	
	printf("\nbefore reversing list is\n");
	print_list(head);
	
	reverse_in_pair(head);
	
	printf("\nafter reversing list is\n");
	print_list(head);
	
	return 0;
}

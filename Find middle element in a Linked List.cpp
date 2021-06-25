/** if number of elements is odd then middle element will be at (n/2)+1 position and if number of
elements is even then middle element will be at (n/2) position. e.g. 1 2 3 4 5 --> mid value=3
e.g. 1 2 3 4 --> mid value=3 (actually its 2 and 3 but we are considering the later one) */

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *head=NULL;

void new_node(int data)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	nn->data=data;
	nn->link=NULL;
	
	if(head==NULL)
		head=nn;
	else
	{
		struct node *temp=head;
		
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=nn;
	}
}

int find_middle_element_1()
{
	int count=0,i=0;
	struct node *temp=head;
	 
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	
	temp=head;
	
	if(count%2!=0)
	{
		while(i<=(count/2)+1)
		{
			temp=temp->link;
		}
		return temp->data;
	}
	
	else
	{
		while(i<=(count/2))
		{
			temp=temp->link;
		}
		return temp->data;
	}
}

int find_middle_element_2()
{
	struct node *fast=head, *slow=head;
	
	while(fast->link!=NULL)
	{
		slow=slow->link;
		fast=slow->link;
	}
	return slow->data;
}

int main()
{
	int i,n,x;
	printf("enter count of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&x);
		new_node(x);
	}
	
	printf("middle element form way 1 is:%d and by way 2 is:%d",find_middle_element_2(),find_middle_element_2());
	
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct node
{
	char name;
	int ex_time, rem_time;
	struct node *link;
};

struct node *head=NULL;

void create_node(char ch, int et)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	struct node *temp;
	 
	nn->link=NULL;
	nn->ex_time=et;
	nn->rem_time=et;
	nn->name=ch;
	
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

struct node* delete_node(struct node *dnode)
{
	struct node *temp1, *temp2;
	
	if(dnode->link==head && head==dnode)     //deleting last node of the list
	{
		head=NULL;
		return head;
	}
	
	else if(dnode->link==head)     //deleting from end of the list
	{
		temp1=head;
		
		while(temp1->link!=head)
		{
			temp2=temp1;
			temp1=temp1->link;
		}
		
		temp2->link=head;
		return temp2;
	}
	
	else if(head==dnode)    	//delete from begining of the list
	{
		head=dnode->link;
		return head;
	}
	
	else	//deleting from a perticular position from list
	{
		temp1=head;
		
		while(temp1->link!=dnode)
		{
			temp1=temp1->link;
		}
		
		temp1->link=dnode->link;
		return temp1;
	}
	
}

void round_robin(struct node *strt, int tq)
{
	int t_ext=0,i=1;
	struct node *temp;
	
	while(head!=NULL)
	{
		strt->rem_time-=tq;
		t_ext+=tq;
		
		if(strt->rem_time<=0)
		{
			temp=strt;
			t_ext+=strt->rem_time;
			
			printf("%c %d\n",strt->name,t_ext);
			strt=delete_node(strt);
			
			if(strt==head)
				strt=head;
			else
				strt=strt->link;
		}
		else
			strt=strt->link;
	}
}

void print_list(struct node *strt)
{
	struct node *temp=strt;
	
	if(strt==NULL)
		printf("list is empty");
	else
	{
		while(strt->link!=temp)
		{
			printf("%c %d\n",strt->name,strt->ex_time);
			strt=strt->link;
		}
		printf("%c %d\n",strt->name,strt->ex_time);
	}
}

int main()
{
	int n,tq,i,et,ch;
	
	printf("enter number of processes:");
	scanf("%d",&n);
	printf("enter time quantum:");
	scanf("%d",&tq);
	
	for(i=0,ch=65;i<n;i++,ch++)
	{
		printf("enter execution time:");
		scanf("%d",&et);
		create_node(ch,et);
	}
	
	round_robin(head,tq);
//	print_list(head);
	
	return 0;
}

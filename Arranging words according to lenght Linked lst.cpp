#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char str[20];
	struct node *link;
};

struct node *head=NULL;

void swap(struct node *strt, struct node *nn)
{
	struct node *temp=strt;
	char tstr[20];
	
	while(temp->link!=NULL)
	{
		if(strlen(temp->str)>strlen(nn->str))
		{
			strcpy(tstr,temp->str);
			strcpy(temp->str,nn->str);
			strcpy(nn->str,tstr);
		}
		temp=temp->link;
	}
}

void create_node(char s[])
{
	int i;
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	struct node *temp;
	
	nn->link=NULL;
	for(i=0;i<strlen(s);i++)
	{
		nn->str[i]=s[i];
	}
	nn->str[i]='\0';
	
	if(head==NULL)
		head=nn;
	else
	{
		temp=head;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=nn;
		swap(head,nn);
	}
}

void reverse_list(struct node *strt)
{
	struct node *cur;
	struct node *pre=NULL;
	struct node *next=NULL;
	
	cur=strt;
	
	while(cur!=NULL)
	{
		next=cur->link;
		cur->link=pre;
		pre=cur;
		cur=next;
	}
	head=pre;
}

void print_list(struct node *strt)
{
	if(strt==NULL)
		printf("lsit is empty");

	printf("\n\n");
	
	while(strt!=NULL)
	{
		printf("%s\t",strt->str);
		strt=strt->link;
	}
}

int main()
{
	int i,n;
	char s[20];
	printf("enter total number of words:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter a word:");
		scanf("%s",s);
		create_node(s);
	}
	
	print_list(head);
	reverse_list(head);
	print_list(head);
	
	return 0;
}

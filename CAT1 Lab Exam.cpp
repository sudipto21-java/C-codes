#include<stdio.h>
#include<stdlib.h>

struct node
{
	int shares,cost;
	struct node *link;
};

struct node *rear=NULL;
struct node *front=NULL;

void enqueue(int sh, int co)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	
	nn->shares=sh;
	nn->cost=co;
	nn->link=NULL;
	
	if(front==NULL && rear==NULL)
		rear=front=nn;
	else
	{
		rear->link=nn;
		rear=nn;
	}
}

void dequeue()
{
	struct node *temp=front;
	
	if(temp==NULL)
		printf("stocks are empty");
	else if(front==rear)
		front=rear=NULL;
	else
	{
		front=front->link;
	}
		
	free(temp);
}

void capital_gain()
{
	int gain=0,sold,rem_sh,sp;
	struct node *ftemp, *rtemp;
	
	rtemp=rear;
	ftemp=front;
	
	sold=rtemp->shares;
	sp=rtemp->cost;
	
	while(sold>0)
	{
		rem_sh=sold;
		sold-=ftemp->shares;
		if(sold>0)
		{
			gain+=ftemp->shares*(sp-ftemp->cost);
		}
		else
		{
			gain+=rem_sh*(sp-ftemp->cost);
		}
		ftemp=ftemp->link;
	}
	
	printf("\n\ncapital gain is:%d",gain);
}

void print_queue(struct node *head)
{
	int i=1;
	printf("      shares   cost\n");
	while(head!=NULL)
	{
		printf("Day%d: %d\t%d\n",i++,head->shares,head->cost);
		head=head->link;
	}
}

int main()
{
	int day,i,share,cost;
	
	printf("enter number of days:");
	scanf("%d",&day);
	
	for(i=0;i<day;i++)
	{
		printf("enter number of shares:");
		scanf("%d",&share);
		printf("enter cost of shares:");
		scanf("%d",&cost);
		enqueue(share,cost);
	}
	
	printf("\nstocks of %d days are\n\n",day);
	print_queue(front);
	
	capital_gain();
	
	return 0;
}

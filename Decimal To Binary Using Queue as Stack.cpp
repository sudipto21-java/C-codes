#include<stdio.h>
#include<stdlib.h>

struct Qnode
{
	int rem;
	struct Qnode *link;
};

struct Qnode *front=NULL, *rear=NULL;

void enqueue(int r)
{
	struct Qnode *nn=(struct Qnode*) malloc(sizeof(struct Qnode));
	struct Qnode *temp;
	
	nn->rem=r;
	nn->link=NULL;
	
	if(front==NULL && rear==NULL)
		front=rear=nn;
	else
		rear->link=rear=nn;
}

int dequeue()
{
	struct Qnode *temp=front;
	
	if(front==rear)
		front=rear=NULL;
	else
		front=front->link;

	return temp->rem;
}

int count()
{
	int c=0;
	struct Qnode *temp=front;
	
	while(temp!=NULL)
	{
		c++;
		temp=temp->link;
	}
	return c;
}

void print()
{
	struct Qnode *temp=front;
	
	while(temp!=NULL)
	{
		printf("%d",temp->rem);
		temp=temp->link;
	}
}

void DecToBin(int n)
{
	int cnt,rem,dq;
	
	while(n!=0)
	{
		cnt=count();
		rem=n%2;
		n/=2;
		enqueue(rem);
		while(cnt>0)
		{
			dq=dequeue();
			enqueue(dq);
			--cnt;
		}
	}
	
	printf("\nBinary equivalent is:");
	print();
}

int main()
{
	int num;
	printf("enter a number:");
	scanf("%d",&num);
	DecToBin(num);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int temp;
	struct stack *link; 
};

struct stack2
{
	int temp;
	struct stack2 *link; 
};

struct stack *top=NULL;
struct stack2 *top2=NULL;

void find_min_temp(int t)
{
	struct stack2 *nn=(struct stack2*) malloc(sizeof(struct stack2));
	
	if(top2==NULL)
	{
		nn->temp=t;
		nn->link=top2;
		top2=nn;
	}	
	
	else
	{
		if(t<top2->temp)
		{
			nn->temp=t;
			nn->link=top2;
			top2=nn;
		}
		else
		{
			nn->temp=top2->temp;
			nn->link=top2;
			top2=nn;
		}
	}
}

void push(int t)
{
	struct stack *nn=(struct stack*) malloc(sizeof(struct stack));
	
	nn->temp=t;
	nn->link=top;
	top=nn;
	
	find_min_temp(top->temp);
}

int pop()
{
	int d=top->temp;
	top=top->link;
	return d;
}

int pop2()
{
	int d=top2->temp;
	top2=top2->link;
	return d;
}

int main()
{
	int n,i,x;
	printf("enter how many temperatures you wanna store:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter temperature:");
		scanf("%d",&x);
		push(x);
	}
	
	printf("\nminimum temperature is:%d",top2->temp);
	return 0;
}

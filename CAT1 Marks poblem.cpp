#include<stdio.h>
#include<stdlib.h>

struct node
{
	int marks;
	struct node *fwd, *bwd;
};

struct node *head=NULL, *tail=NULL;

void create_node(int m)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	struct node *cur;
	
	nn->marks=m;
	nn->fwd=nn->bwd=NULL;
	
	if(head==NULL && tail==NULL)
	{
		head=tail=nn;
	}
	
	else
	{
		cur=head;
		while(cur->fwd!=NULL)
		{
			cur=cur->fwd;
		}
		cur->fwd=tail=nn;
		nn->bwd=cur;
	}	
}

void swap_marks(int *a1, int *a2)
{
	int temp=*a1;
	*a1=*a2;
	*a2=temp;
}

void calc()
{
	struct node *strt, *last;
	
	strt=head;
	last=tail;
	
	while(strt->marks!=last->marks)
	{
		if(strt->marks<15)
		{
			strt=strt->fwd;
		}
		
		else if(last->marks>=15)
		{
			last=last->bwd;
		}
		
		else
		{
			swap_marks(&strt->marks, &last->marks);
		}
	}
}

void print()
{
	struct node *strt, *last;
	
	strt=head;
	last=tail;
	
//	printf("traverse from begining of the list\n");
	
	while(strt!=NULL)
	{
		printf("%d\n",strt->marks);
		strt=strt->fwd;
	}
	
/*	printf("traverse from end of the list\n");
	
	while(last!=NULL)
	{
		printf("%d\n",last->marks);
		last=last->bwd;
	}  */
}

int main()
{
	int i,n,x;
	printf("enter number of students:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter marks:");
		scanf("%d",&x);
		create_node(x);
	}
	
	calc();
	print();
	return 0;
}

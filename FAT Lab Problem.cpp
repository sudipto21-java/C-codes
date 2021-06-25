#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int data;
	struct stack *link;
};

struct stack *top=NULL;

void push(int val)
{
//	printf("push\n");
	struct stack *nn=(struct stack*) malloc(sizeof(struct stack));
	
	nn->data=val;
	nn->link=NULL;
	
	nn->link=top;
	top=nn;
}

void swap(int *a1, int *a2)
{
//	printf("swap\n");
	int t=*a1;
	*a1=*a2;
	*a2=t;
}

void select_sort_asc(int ar[], int size)
{
//	printf("select_sort_asc\n");
	int i,j,mi;
	for(i=0;i<size;i++)
	{
		mi=i;
		for(j=i+1;j<size;j++)
		{
			if(ar[j]<ar[mi])
			{
				mi=j;
			}
		}
		swap(&ar[mi],&ar[i]);
	}
}

void select_sort_desc(int ar[], int size)
{
//	printf("select_sort_desc\n");
	int i,j,mi;
	for(i=0;i<size;i++)
	{
		mi=i;
		for(j=i+1;j<size;j++)
		{
			if(ar[j]>ar[mi])
			{
				mi=j;
			}
		}
		swap(&ar[mi],&ar[i]);
	}
}

void calculate()
{
//	printf("calculate\n");
	int diff;
	while(top->data!=diff)
	{
		int i,n,dig1,dig2,small=0,large=0,count=3,top_el;
 		top_el=top->data;
		int ar_desc[4], ar_asc[4], ar[4], temp1[4], temp2[4];
		
		while(top_el!=0)
		{
			ar[count]=top_el%10;
			top_el/=10;
			--count;
		}
		
/*		for(i=0;i<4;i++)
		{
			printf("%d",ar[i]);
		}
		
		printf("\n");      */
		
		for(i=0;i<4;i++)
		{
			temp1[i]=ar[i];
			temp2[i]=ar[i];
		}
		
		select_sort_asc(temp1,4);
		
/*		for(i=0;i<4;i++)
		{
			printf("%d",temp1[i]);
		}

		printf("\n");  */
		
		select_sort_desc(temp2,4);
		
/*		for(i=0;i<4;i++)
		{
			printf("%d",temp2[i]);
		}
		
		printf("\n");      */
	
		for(i=0;i<4;i++)
		{
			small*=10;
			small+=temp1[i];
		}
		
//		printf("small number is:%d\n",small);
	
		for(i=0;i<4;i++)
		{
			large*=10;
			large+=temp2[i];
		}
		
//		printf("large number is:%d\n",large);
	
		diff=large-small;
//		printf("diff is:%d\n",diff);
	
		if(top->data!=diff)
		{	
			push(diff);
			diff=0;
		}
		
//		printf("top is:%d\n",top->data);
	}
//	printf("end of calculate\n");
}

int main()
{
	int num;
	
	printf("enter a 4 digit number:");
	scanf("%d",&num);
		
	push(num);
//	printf("top element is:%d\n",top->data);
	
	calculate();
	printf("Answer is:%d",top->data);
	
	return 0;
}

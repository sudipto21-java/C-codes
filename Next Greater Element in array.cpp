#include<stdio.h>

int top=-1, stack[10];

void push(int d)
{
	stack[top++]=d;
}

void pop()
{
	--top;
}

void print_arr_nge(int a[], int n)
{
	printf("\nnext greater elements are\n");
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

void find_next_greater_element_bfa(int a[], int n)	    // time complexity O(n^2)
{
	int i,j,arr_nge[n],nge,f=0;
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]<a[j])
			{
				f=1;
				break;				
			}
		}
		
		if(f==1)
			arr_nge[i]=a[j];	
		else
			arr_nge[i]=-1;
	}
	
	print_arr_nge(arr_nge,n);
}

find_next_greater_element_optimised(int a[], int n)
{
	int i,peek,arr_nge[n];
	push(0);
	for(i=0;i<n;i++)
	{
		if(a[stack[top]]>a[i] || top==-1)
			push(i);
			
		else
		{
			while(a[stack[top]]<a[i])
			{
				peek=stack[top];
				pop();
				arr_nge[peek]=a[i];
			}
			push(i);
		}
	}
	print_arr_nge(arr_nge,n);
}

int main()
{
	int a[10],i,n;
	
	printf("enter size of array:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&a[i]);
	}
	
	find_next_greater_element_bfa(a,n);
	find_next_greater_element_optimised(a,n);
	
	return 0;
}

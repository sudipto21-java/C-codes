#include<stdio.h>

void swap(int *p1, int *p2)
{
	int t=*p1;
	*p1=*p2;
	*p2=t;
}

void bubble_sort(int a[], int n)
{
	int i,j;
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
			}
		}
	}
}

void bubble_sort_optimised(int a[], int n)
{
	int i,j,f;
	
	for(i=0;i<n-1;i++)
	{
		f=0;
		
		for(j=0;j<n-i-1;j++)  		//last i elements are already sorted so skip comparing them
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
				f=1;
			}
		}
		
		if(f==0)
			break;
	}
}

void print(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

int main()
{
	int a[10],n,i;
	printf("enter number of elements:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter an element:");
		scanf("%d",&a[i]);
	}
		
	bubble_sort_optimised(a,n);
	printf("Sorted array is\n");
	print(a,n);
	return 0;
}

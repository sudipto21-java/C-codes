#include<stdio.h>

void insertion_sort(int a[], int n)
{
	int i,j,t;
	
	for(i=1;i<n;i++)
	{
		t=a[i];
		
		for(j=i-1; j>=0 && a[j]>t; j--)
		{
			a[j+1]=a[j];
		}
		
		a[j+1]=t;
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
		
	insertion_sort(a,n);
	printf("Sorted array is\n");
	print(a,n);
	return 0;
}

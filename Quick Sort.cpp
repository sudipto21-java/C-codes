#include<stdio.h>

void swap(int *p1, int *p2)
{
	int t=*p1;
	*p1=*p2;
	*p2=t;
}

int partition(int a[], int lb, int ub)
{
	int pivot=a[ub];
	int pidx=lb,i;
	
	for(i=lb;i<ub;i++)
	{
		if(a[i]<=pivot)
		{
			swap(&a[i],&a[pidx]);
			pidx+=1;
		}
	}
	swap(&a[pidx],&a[ub]);    // pidx can be swapped with a[i] as well, it will produce same result
	return pidx;
}

void quick_sort(int a[], int lb, int ub)
{
	if(lb<ub)
	{
		int pidx=partition(a,lb,ub);
		quick_sort(a,lb,pidx-1);
		quick_sort(a,pidx+1,ub);
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
		
	quick_sort(a,0,n-1);
	printf("Sorted array is\n");
	print(a,n);
	return 0;
}

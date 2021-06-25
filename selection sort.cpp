#include<stdio.h>

void swap(int *a1, int *a2)
{
	int t=*a1;
	*a1=*a2;
	*a2=t;
}

void select_sort(int a[], int size)
{
	int i,j,min_idx;
	
	for(i=0;i<size-1;i++)
	{
		min_idx=i;
		
		for(j=i+1;j<size;j++)
		{
			if(a[j]<a[min_idx])
			{
				min_idx=j;
		    }
	    }	
		swap(&a[min_idx],&a[i]);	  
	}
}

int main()
{
	int a[10],i;
	int n;
	printf("enter number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&a[i]);
	}
	
	select_sort(a,n);
	
	printf("after sorting elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}

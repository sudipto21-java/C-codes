#include<stdio.h>

void swap(int *a1, int *a2)
{
	int t=*a1;
	*a1=*a2;
	*a2=t;
}

int sum(int num)
{
	int t,s=0;
	while(num>=1)
	{
		t=num%10;
		s+=t;
		num=num/10;
	}
	return s;
}

void sort(int a[],int size)
{
	int mi,i,j,s1,s2;
	for(i=0;i<size-1;i++)
	{
		mi=i;
		for(j=i+1;j<size;j++)
		{
			s1=sum(a[j]);
			s2=sum(a[mi]);
			if(s1<s2)
				mi=j;
		}
		swap(&a[mi],&a[i]);
	}
}

int main()
{
	int arr[10],i,n;
	printf("enter number of elements:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&arr[i]);
	}
	
	sort(arr,n);
	printf("after sorting\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}

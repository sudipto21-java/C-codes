#include<stdio.h>

void get_prefix_sum_1(int a[], int prefix_sum[], int n)		// time O(n) , space O(1)
{
	int i,j,sum=0;
	for(i=0;i<n;i++)
	{
		for(j=i;j<=i;j++)
		{
			sum+=a[j];
		}
		prefix_sum[i]=sum;
	}
}

void get_prefix_sum_2(int a[], int prefix_sum[], int n)		// time O(n) , space O(1)
{
	int i;
	prefix_sum[0]=a[0];
	
	for(i=0;i<n;i++)
	{
		prefix_sum[i+1]=prefix_sum[i]+a[i+1];
	}
}

void print_arr(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}

int main()
{
	int i,n,k;
	
	printf("enter size of array:");
	scanf("%d",&n);
	
	int a[n],prefix_sum[n];
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		prefix_sum[i]=a[i];
	}
	
	get_prefix_sum_1(a,prefix_sum,n);
	print_arr(prefix_sum,n);
	
	get_prefix_sum_2(a,prefix_sum,n);
	print_arr(prefix_sum,n);
	
	return 0;
}

#include<stdio.h>

void generate_subarrays(int a[], int n)		// time O(n^3) , space O(1)
{
	int i,j,k;
	
	for(i=0;i<n;i++)		// select start position
	{
		for(j=i;j<n;j++)		// select end position
		{
			for(k=i;k<=j;k++)		// print from start to end position
			{
				printf("%d",a[k]);
			}
			printf("\n");
		}
	}
}

int main()
{
	int i,n,k;
	
	printf("enter size of array:");
	scanf("%d",&n);
	
	int a[n];
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&a[i]);
	}
	
	generate_subarrays(a,n);
	return 0;
}

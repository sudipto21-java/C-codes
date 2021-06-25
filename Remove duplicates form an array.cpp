#include<stdio.h>

int remove_duplicates(int a[], int n)		// time O(n) , space O(1)
{
	int i=0,j;
	
	for(j=1;j<n;j++)
	{
		if(a[i]!=a[j])
		{
			i++;
			a[i]=a[j];
		}
	}
	return i+1;
}

int main()
{
	int n,i,pos;
	printf("enter size of array:");
	scanf("%d",&n);
	
	int a[n];
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&a[i]);
	}
	
	pos=remove_duplicates(a,n);
	printf("after removal of duplicates array is\n");
	for(i=0;i<pos;i++)
	{
		printf("%d\t",a[i]);
	}
	
	return 0;
}

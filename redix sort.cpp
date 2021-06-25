#include<stdio.h>

int max_ele(int a[], int n)
{
	int i;
	int max=a[0];
	for(i=0;i<n;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	return max;
}

void count_sort(int a[], int n, int pos)
{
	int count[10]={0};
	int cpy[n],i;
	
	for(i=0;i<n;i++)
	{
		++count[(a[i]/pos)%10];
	}
	
	for(i=1;i<10;i++)
	{
		count[i]+=count[i-1];
	}
	
	for(i=n-1;i>=0;i--)
	{
		cpy[count[(a[i]/pos)%10]-1]=a[i];
		--count[(a[i]/pos)%10];
	}
	
	for(i=0;i<n;i++)
	{
		a[i]=cpy[i];
	}
}

void redix(int a[], int n)
{
	int i,pos;
	int max=max_ele(a,n);
	for(pos=1;max/pos>0;pos*=10)
	{
		count_sort(a,n,pos);
	}
}

int main()
{
	int a[10],i,n,size;
	printf("enter number of elements:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter number:");
		scanf("%d",&a[i]);
	}
	
	redix(a,n);
	printf("after sorting elements are\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	
	return 0;
}

#include<stdio.h>

void swap(int *a1, int *a2)
{
	int t=*a1;
	*a1=*a2;
	*a2=t;
}

void sort_array(int a[], int n)
{
	int i,j,mi;
	for(i=0;i<n;i++)
	{
		mi=i;
		for(j=i+1;j<n;j++)
		{
			if(a[mi]>a[j])
				mi=j;
		}
		swap(&a[mi],&a[i]);
	}
}

void getFrequency(int a[], int n)
{
	sort_array(a,n);
	
	int i,j,c=0;
	
	for(i=0,j=0;i<n;i=j)
	{
		while(a[i]==a[j] && j<n)
		{
			j++;
			c++;
		}
		printf("count of %d is %d\n",a[i],c);
		c=0;
	}
}

int main()
{
	int i,a[10],n;
	printf("enter size of array:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	getFrequency(a,n);
	return 0;
}

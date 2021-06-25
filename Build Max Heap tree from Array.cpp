#include<stdio.h>

void swap(int *p1, int *p2)
{
	int t=*p2;
	*p2=*p1;
	*p1=t;
}

void heapify(int a[], int n, int i)
{
	int lar=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n && a[l]>a[lar])
		lar=l;
	
	if(r<n && a[r]>a[lar])
		lar=r;
		
	if(lar!=i)
	{
		printf("%d ",lar);
		swap(&a[i], &a[lar]);
		heapify(a,n,lar);
	}
}

void build_heap(int a[], int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		heapify(a,n,i);
	}
}

int main()
{
	int a[20],n,i;
	printf("enter size of array:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&a[i]);
	}
	
	build_heap(a,n);
	
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

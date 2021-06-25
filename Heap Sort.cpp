#include<stdio.h>

void swap(int *p1, int *p2)
{
	int t=*p2;
	*p2=*p1;
	*p1=t;
}

void heapify(int a[], int n, int i)
{
	int lar,l,r;
	lar=i;
	l=2*i+1;
	r=2*i+2;
	
	if(l<n && a[l]>a[lar])
		lar=l;
	
	if(r<n && a[r]>a[lar])
		lar=r;
		
	if(lar!=i)
	{
		swap(&a[lar], &a[i]);
		heapify(a,n,lar);
	}
}

void heap_sort(int a[], int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		heapify(a,n,i);
	}
	
	for(int i=n-1;i>=0;i--)
	{
		swap(&a[0],&a[i]);
		printf("%d\n",i);
		heapify(a,i,0);
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
	
	heap_sort(a,n);
	
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

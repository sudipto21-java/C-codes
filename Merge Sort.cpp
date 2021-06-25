#include<stdio.h>

void merge(int a[], int l, int m, int r)
{
	int sizeL,sizeR,i,j,k;
	
	sizeL=m-l+1;
	sizeR=r-m;
	
	int L[sizeL], R[sizeR];
	
	for(i=0;i<sizeL;i++)
	{
		L[i]=a[l+i];
	}
		
	for(j=0;j<sizeR;j++)
	{
		R[j]=a[m+1+j];
	}
	
	i=j=0;
	k=l;
	
	while(i<sizeL && j<sizeR)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			++i;
		}
		else
		{
			a[k]=R[j];
			++j;
		}
		++k;
	}
	
	while(i<sizeL)
	{
		a[k]=L[i];
		++i,++k;
	}
	
	while(j<sizeR)
	{
		a[k]=R[j];
		++j,++k;
	}
}

void merge_sort(int a[], int l, int r)
{
	int m;
	
	if(l<r)
	{
		m=l+(r-l)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,r);
		merge(a,l,m,r);
	}
}

int main()
{
	int a[10],i,n;
	
	printf("enter number of elements:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&a[i]);
	}
	
	merge_sort(a,0,n-1);
	
	printf("after sorting elements are\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	
	return 0;
}

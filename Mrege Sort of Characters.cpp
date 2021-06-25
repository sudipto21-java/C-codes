#include<stdio.h>
#include<string.h>

void merge(char carr[], int l, int m, int r)
{
	int i,j,k,sl,sr;
	sl=m-l+1;
	sr=r-m;
	char L[sl];
	char R[sr];
	
	for(i=0;i<sl;i++)
	{
		L[i]=carr[l+i];
	}
	
	for(j=0;j<sr;j++)
	{
		R[j]=carr[m+1+j];
	}
	
	i=j=0;
	k=l;
	
	while(i<sl && j<sr)
	{
		if((int)(L[i]) <= (int)(R[j]))
		{
			carr[k]=L[i];
			++i;
		}
		else
		{
			carr[k]=R[j];
			++j;
		}
		++k;
	}
	
	for(;i<sl;i++,k++)
	{
		carr[k]=L[i];
	}
	
	for(;j<sr;j++,k++)
	{
		carr[k]=R[j];
	}
}

void merge_sort(char carr[], int l, int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		merge_sort(carr,l,m);
		merge_sort(carr,m+1,r);
		merge(carr,l,m,r);
	}
}

int main()
{
	int i,n;
	char carr[10];
	
	printf("enter number of characters:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter a character:");
		scanf(" %c",&carr[i]);
	}
	
	merge_sort(carr,0,n-1);
	printf("after sorting\n");
	
	for(i=0;i<n;i++)
	{
		printf("%c ",carr[i]);
	}
	
	return 0;
}

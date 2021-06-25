#include<stdio.h>

void binary_search(int a[], int n, int el)
{
	int l=0,r=n-1,m,chk=0;
	
	while(l<=r)
	{
		m=(l+r)/2;
		
		if(a[m]==el)
		{
			printf("\nelement %d is found at index %d",el,m+1);
			chk=1;
			break;
		}
		
		else if(a[m]>el)
			r=m-1;
		else
			l=m+1;
	}
	
	if(chk==0)
	{
		printf("element is not present in the array");
	}
}

int main()
{
	int a[10],n,i,el;
	printf("enter number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter an element:");
		scanf("%d",&a[i]);
	}
	printf("enter the element to be searched:");
	scanf("%d",&el);
	binary_search(a,n,el);
	return 0;
}

#include<stdio.h>

void linear_search(int a[], int n, int el)
{
	int i,chk=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==el)
		{
			chk=1;
			break;
		}
	}
	
	if(chk==1)
	{
		printf("\nelement %d is found at index %d",el,i+1);
	}
	else
		printf("element is not present in the array");
	
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
	linear_search(a,n,el);
	return 0;
}

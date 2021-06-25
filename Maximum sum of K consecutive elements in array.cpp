#include<stdio.h>

void sliding_window_technique(int a[], int n, int k)		// time O(n*k) , space O(1)
{
	int res=0,csum=0,i;
	
	for(i=0;i<k;i++)
	{
		res+=a[i];
	}
	
	csum=res;
	
	for(i=k;i<n;i++)
	{
		csum+=a[i]-a[i-k];
		if(csum>res)
			res=csum;
	}
			
	printf("\nmaximum sum is:%d\n",res);
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
	
	printf("enter a number which will represent how many numbers are to be added consecutively:");
	scanf("%d",&k);
	sliding_window_technique(a,n,k);
	return 0;
}

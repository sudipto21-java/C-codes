
/** Given an array A of N positive numbers. The task is to find the first Equilibium Point in the array. 
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of 
elements after it. Return -1 if no such point exists.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1) */

#include<stdio.h>

int equilibrium_point(int a[], int n)
{
	int i,ls=0,rs=0;
	
	if(n==1)
		return 1;
	
	for(i=0;i<n;i++)
	{
		rs+=a[i];
	}
	
	for(i=0;i<n;i++)
	{
		rs-=a[i];
		
		if(rs==ls)
			return i+1;
		
		ls+=a[i];
	}
	
	if(ls!=rs)
		return -1;
}

int main()
{
	int n,i,res;
	
	printf("enter size of array:");
	scanf("%d",&n);
	
	int a[n];
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&a[i]);
	}
	
	if((res=equilibrium_point(a,n))!=-1)
		printf("point is:%d",res);
	else
		printf("point does not exist");
		
	return 0;
}

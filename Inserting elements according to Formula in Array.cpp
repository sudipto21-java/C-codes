/* Create two arrays of lenght l, given by the user. Read 'n' and the n elements. Store the elements in two 
arrays in the location calculated using the following formulae:

l1(x)=(x+1)%l
l2(x)=(x/3)%l

If l1(x) is empty, place x there, Otherwise, place x there, evict the old element y and try placing y into l2 
recursing until we find an empty slot. Finally print two arrays.

Example:

11 (lenght,l)
10 (n)

elements: 20, 50, 53, 75, 100, 67, 105, 3, 36, 39

after completion arrays will be:

l1=[0, 0, 67, 0, 36, 0, 0, 39, 0, 0]
l2=[100, 3, 105, 75, 0, 50, 53, 0, 0, 0] */

#include<stdio.h>

int main()
{
	int i,n,l,x,y;
	
	printf("enter count of elements:");
	scanf("%d",&n);
	
	printf("enter length of arrays:");
	scanf("%d",&l);
	
	int l1[l] , l2[l];
	
	for(i=0;i<l;i++)
	{
		l1[i]=l2[i]=0;
	}
	
	for(i=0;i<n;i++)
	{
		printf("enter a value:");
		scanf("%d",&x);
		
		if(l1[(x+1)%l]==0)
			l1[(x+1)%l]=x;
		else
		{
			while(l1[(x+1)%l]!=0)
			{
				y=l1[(x+1)%l];
				
				if(l2[(y/3)%l]==0)
				{
					l2[(y/3)%l]=y;
					l1[(x+1)%l]=x;
					break;
				}
					
				else
				{
					l1[(x+1)%l]=x;
					x=l2[(y/3)%l];
					l2[(y/3)%l]=y;
				}
			}
		}
	}
	
	for(i=0;i<l;i++)
	{
		printf("%d ",l1[i]);
	}
	
	printf("\n");
	
	for(i=0;i<l;i++)
	{
		printf("%d ",l2[i]);
	}
	
	return 0;
}

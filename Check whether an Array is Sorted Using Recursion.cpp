#include<stdio.h>

int isSorted(int a[], int strt, int size)
{	
	if(strt==size-1)
		return 1;
		
	if(a[strt]>a[strt+1])
		return 0;
		
	int result=isSorted(a,strt+1,size);
	return result;
}

int main()
{
	int a[10]={1,2,3,4,5};
	
	if(isSorted(a,0,5)==1)
		printf("array is sorted");
	else
		printf("array is not sorted");
	return 0;
}

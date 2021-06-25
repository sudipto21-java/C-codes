#include<stdio.h>

int main()
{
	int n,i,j;
	
	printf("enter size of an array for size*size matrix:");
	scanf("%d",&n);
	
	char arr[n][n],ch,temp[n][n];
	
	// initializing array
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("enter a character:");
			scanf(" %c",&ch);
			arr[i][j]=ch;
		}
	}
	
	printf("\nOriginal Array is\n");
	
	// printing original array
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}
	
	//traversing original array and saving changes (row-wise) into temp array
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j-i<0)
				temp[i][(j-i)+n]=arr[i][j];
			else
				temp[i][j-i]=arr[i][j];
		}
	}
	
	//copying temp array into original array
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			arr[i][j]=temp[i][j];
		}
	}
	
	//traversing original array and saving changes (column-wise) into temp array
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			if(i-j<0)
				temp[(i-j)+n][j]=arr[i][j];
			else
				temp[i-j][j]=arr[i][j];
		}
	}
	
	//copying temp array into original array
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			arr[i][j]=temp[i][j];
		}
	}
	
	printf("\nAfter rotation Array is\n");
	
	//priting original changed array
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

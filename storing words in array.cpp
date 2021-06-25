#include<stdio.h>

int main()
{
	int i,n;
	printf("enter number of words:");
	scanf("%d",&n);
	char a[n][20];
	for(i=0;i<n;i++)
	{
		printf("enter word:");
		scanf("%s",a[i]);
	}
	printf("entered words are....\n");
	for(i=0;i<n;i++)
	{
		printf("%s ",a[i]);
	}
}

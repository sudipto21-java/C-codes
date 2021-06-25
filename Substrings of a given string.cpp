#include<stdio.h>
#include<string.h>

void substring(char string[])
{
	int i,j,k,len,n;
	n=strlen(string);
	
	for(len=1;len<=n;len++)
	{
		for(i=0;i<=n-len;i++)
		{
			j=i+len-1;
			
			for(k=i;k<=j;k++)
			{
				printf("%c",string[k]);
			}
			
			printf("\t");
		}
	}
}

int main()
{
	char string[50];
	printf("enter a string\n");
	scanf("%s",string);
	printf("Substrings are\n");
	substring(string);
	return 0;
}

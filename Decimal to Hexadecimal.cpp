#include<stdio.h>

void  DecToHex(int n)
{
	int temp,i=0,j;
	char hexa[10];
	while(n!=0)
	{
		temp=0;
		temp=n%16;
		
		if(temp<10)
		{
			hexa[i]=temp+48;
		}
		else
		{
			hexa[i]=temp+55;
		}
		
		++i;
		n=n/16;
	}
	for(j=i;j>=0;j--)
	{
		printf("%c",hexa[j]);
	}
}

int main()
{
	int n;
	printf("enter a decimal number:");
	scanf("%d",&n);
	
	DecToHex(n);
	return 0;
}

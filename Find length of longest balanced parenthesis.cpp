#include<stdio.h>
#include<stdlib.h>

int get_length(char exp[], int size)
{
	int len,i,sum=0;
	
	for(i=0;i<size;i++)
	{
		if(exp[i]=='(')
			sum++;
		else
			sum--;
			
		if(sum==0)
			len=i+1;
	}
	return len;
}

void print_expression(char exp[], int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%c",exp[i]);
	}
}

int main()
{
	char exp[50];
	int n,i;
	printf("enter total count of characters\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter a character:");
		scanf(" %c",&exp[i]);
	}
	exp[i]='\0';
	
	printf("expression is\n");
	print_expression(exp,n);
	printf("\nLenght of longest balanced parenthesis is: %d",get_length(exp,n));

	return 0;
}

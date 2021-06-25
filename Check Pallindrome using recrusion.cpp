#include<stdio.h>
#include<string.h>

void isPallindrome(char string[])
{
	int lb,ub,f=0;
	for(lb=0,ub=strlen(string)-1;lb!=ub;lb++,ub--)
	{
		if(string[lb]==string[ub])
		{
			f=1;
			continue;
		}
		else
			break;
			
		f=0;
	}
	
	if(f==1)
		printf("%s is a pallindrome string\n",string);
	else
		printf("%s is not pallindrome string\n",string);
}

int isPallindrome_r(char string[], int lb, int ub)
{
	if(string[lb]!=string[ub])
		return 0;
		
	if(lb==ub)
		return 1;
	
	int result=isPallindrome_r(string,++lb,--ub);
	return result;
}

int main()
{
	char string[50];
	printf("enter a string\n");
	scanf("%s",string);
	
	printf("Using iterative approach\n");
	isPallindrome(string);
	printf("Using recursive approach\n");
	
	if(isPallindrome_r(string,0,strlen(string)-1)==1)
		printf("%s is a pallindrome string\n",string);
	else
		printf("%s is not pallindrome string\n",string);
		
	return 0;
}

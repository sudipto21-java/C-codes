#include<stdio.h>

int factorial(int n)
{
	if(n==1)
		return 1;
		
	return n*factorial(n-1);
}

int main()
{
	int x;
	printf("enter a number:");
	scanf("%d",&x);
	
	printf("factorial of %d is %d",x,factorial(x));
	return 0;
}

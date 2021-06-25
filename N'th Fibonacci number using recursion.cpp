#include<stdio.h>

int fib_n(int n)
{
	int i=0,j=1,ans,c=1;
	while(c++<=n)
	{
		ans=i+j;
		i=j;
		j=ans;
	}
	return ans;
}

int fib_r(int n)		 // using recursion
{
	if(n<=1)	// n<=0 condition will provide wrong answer
		return 1;
		
	return fib_r(n-1)+fib_r(n-2);
}

int main()
{
	int n;
	printf("enter n'th fibonacci value you wanna get\n");
	scanf("%d",&n);
	printf("Naive approach:%d\nUsing recursion:%d",fib_n(n),fib_r(n));
	return 0;
}

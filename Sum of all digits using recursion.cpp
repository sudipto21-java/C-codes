#include<stdio.h>

int sum_n(int n)
{
	int rem,sum=0;
	while(n>0)
	{
		rem=n%10;
		sum+=rem;
		n/=10;
	}
	return sum; 
}

int sum_r(int n)
{
	if(n==0)
		return 0;
	int sum=sum_r(n/10);
	return sum+n%10;
}

int main()
{
	int n;
	printf("enter a number for which you wanna get sum of all digits\n");
	scanf("%d",&n);
	printf("Naive approach:%d\nUsing recursion:%d",sum_n(n),sum_r(n));
	return 0;
}

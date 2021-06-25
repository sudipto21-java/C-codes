#include<stdio.h>
#include<math.h>

int gcd(int a, int b)
{
	if(b==0)
		return a;
		
	return gcd(b,a%b);
}

int small_divisible_num(int n)  // n=3 then 6 will be smallest and divisible by 1,2,3 i.e. lcm(1,2,3)
{
	int s=1;
	
	for(int i=1;i<=n;i++)
	{
		s=s*i/gcd(s,i);    // calculating lcm
	}
	return s;
}

int main()
{
	int n;
	printf("enter a number:");
	scanf("%d",&n);
	printf("smallest divisible number is:%d",small_divisible_num(n));
	return 0;
}

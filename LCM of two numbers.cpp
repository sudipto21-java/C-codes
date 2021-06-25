#include<stdio.h>

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int get_max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int get_min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int lcm_m1(int a, int b)    // using gcd
{
	int hcf=gcd(a,b);
	int lcm=(a*b)/hcf;
	return lcm;
}

int lcm_m2(int a, int b)    // without using gcd
{
	int min=get_min(a,b);
	int max=get_max(a,b);
	
	for(int i=max;;i+=max)
	{
		if(i%min==0)
			return i;
	}
}

int main()
{
	int a,b;
	printf("enter two numbers\n");
	scanf("%d%d",&a,&b);
	printf("lcm is:%d",lcm_m2(a,b));
	return 0;
}

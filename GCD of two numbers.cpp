#include<stdio.h>

int get_min(int n1, int n2)
{
	if(n1>n2)
		return n1;
	else
		return n2;
}

int gcd_m1(int n1,int n2)
{
	int min=get_min(n1,n2);
	
	if(n1%min==0 && n2%min==0)
		return min;
	
	for(int i=min/2;i>=2;i--)
	{
		if(n1%i==0 && n2%i==0)
			return i;
	}
}

//Euclidian method 

int gcd_euclid_m2(int n1, int n2)
{
	if(n2==0)
		return n1;
	
	return gcd_euclid_m2(n2, n1%n2);
}

int gcd_m3(int n1, int n2)
{
	if(n1==0)
		return n2;
	if(n2==0)
		return n1;
	
	if(n1>n2)
		gcd_m3(n1-n2,n2);    //(n2,n1-n2)
	else
		gcd_m3(n1,n2-n1);	//(n2,n2-n1)
}

int main()
{
	int n1,n2;
	printf("enter two numbers\n");
	scanf("%d%d",&n1,&n2);
	printf("GCD of %d and %d is:%d,%d",n1,n2,gcd_euclid_m2(n1,n2),gcd_m3(n1,n2));
	return 0;
}

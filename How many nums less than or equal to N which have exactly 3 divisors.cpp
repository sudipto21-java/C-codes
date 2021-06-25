#include<stdio.h>
#include<math.h>

int getCount(int n)
{
	int c=0,i;
	for(i=1;i<=n;i++)
	{
		if(n%i==0)
			c++;
	}
	return c;
}

int get3Divisors_m1(int n)     // time complexity is O(n^2) 
{
	int i,count, total=0;
	for(i=1;i<=n;i++)
	{
		count=getCount(i);
		if(count==3)
			total++;
	}
	return total;
}

bool isPrime(int n)
{
	if(n==1)
		return false;
		
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return false;
	}
	
	return true;
}

int get3Divisors_m2(int n)    // time complexity is O(n^1/2 * n^1/4)
{
	int i,count=0;
	
	for(i=1;i<=sqrt(n);i++)      // condition could also be i*i<=n; but both are same
	{
		if(isPrime(i)==true && i*i<=n)
		{
			count++;
		}
	}
	
	return count;
}

int main()
{
	int n;
	printf("enter a num for which you wanna know the count of numbers which have 3 divisors exactly\n");
	scanf("%d",&n);
	printf("total count is:%d",get3Divisors_m2(n));
	return 0;
}

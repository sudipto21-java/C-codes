#include<stdio.h>
#include<math.h>

bool IsPrime(int n)     // time complexity=O(sqrt n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	printf("enter the number which you wanna check whether it is prime or not\n");
	scanf("%d",&n);
	
	if(IsPrime(n)==false)
		printf("%d is not prime",n);
	else
		printf("%d is prime",n);
		
	return 0;
}

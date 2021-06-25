#include<stdio.h>
#include<math.h>

int CountDigits(int n)
{
	double d=0;
	
	if(n==0)
		return 1;
	
	for(int i=1;i<=n;i++)
	{
		d+=log10(i);
	}
	return floor(d)+1;
}

/* above method has a limitation n<=10^6 above it we use kamenetskey's method 
   f(x)=n*log(n/e)base10 + (log(2*pi*n)base10)/2 */

int main()
{
	int n;
	printf("enter a number:");
	scanf("%d",&n);
	printf("total digits in %d! is:%d",n,CountDigits(n));
	return 0;
}

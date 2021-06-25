#include<stdio.h>
#include<math.h>

int trail_zero(int n)
{
	int tz=0;
	for(int i=5;n>=i;i*=5)
	{
		tz+=n/i;
	}
	return tz;
}

int main()
{
	int n;
	printf("enter a number:");
	scanf("%d",&n);
	printf("trailing zeros in %d! is:%d",n,trail_zero(n));
	return 0;
}

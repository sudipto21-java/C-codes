#include<stdio.h>
#include<math.h>

void Total_Digits_m1(int n)    // method1   time complexity O(digits)
{
	int c=0;
	while(n>0)
	{
		n/=10;
		c++;
	}
	printf("total digits are:%d",c);
}

void Total_Digits_m2(double n)
{
	int c=floor(log10(n))+1;
	printf("total digits are:%d",c);
}

int main()
{
	double n;
	printf("enter a number:");
	scanf("%lf",&n);
	Total_Digits_m2(n);
	return 0;
}

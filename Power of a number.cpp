#include<stdio.h>

int power_m1(int b,int e)
{
	int pow=b;
	
	if(e==0)
		return 1;
		
	else if(e==1)
		return b;
		
	else
	{
		for(int i=2;i<=e;i++)
		{
			pow*=b;
		}
		return pow;
	}
}

int main()
{
	int base,exp;
	printf("enter base and exponent\n");
	scanf("%d%d",&base,&exp);
	printf("%d^%d=%d",base,exp,power_m1(base,exp));
	return 0;
}

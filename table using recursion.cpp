#include<stdio.h>

void table(int val)
{
	int i;
    for(i=1;i<=10;i++)
	{
		printf("%d\n",val);
		table(val*i);
	}
}

void table_2(int val, int i)
{
	if(i==1)
		printf("%d\n",val*i);
		
	table_2(val,i--);
}

int main()
{
	int n;
    printf("enter number:");
    scanf("%d",&n);
    table_2(n,10);
    printf("Thank You");
    return 0;
}

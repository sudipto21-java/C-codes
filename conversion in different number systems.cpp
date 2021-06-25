#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>

int main()
{
	int i,n;
	char result[10];
	char str[10];
	printf("enter a number:");
	scanf("%d",&i);
	
	itoa(i,result,10);
	printf("decimal equivalent is:%s",result);
	itoa(i,result,2);
	printf("\nbinary equivalent is:%s",result);
	itoa(i,result,8);
	printf("\noctal equivalent is:%s",result);
	itoa(i,result,16);
	printf("\nhexadecimal equivalent is:%s",result);
	
	return 0;
}

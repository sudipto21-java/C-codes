#include<stdio.h>
#include<string.h>

int HexToDec(char s[])
{
	int dec=0,i,base=1,len=strlen(s);
	for(i=len-1;i>=0;i--)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			dec+=(s[i]-48)*base;
			base*=16;
		}
		else if((s[i]>='A' && s[i]<='F') || (s[i]>='a' && s[i]<='f'))
		{
			dec+=(s[i]-55)*base;
			base*=16;
		}
	}
	return dec;
}

int main()
{
	char hex[10];
	int res;
	printf("enter hexadecimal number:");
	scanf("%s",&hex);
	res=HexToDec(hex);
	printf("decimal equivalent is:%d",res);
	return 0;
}

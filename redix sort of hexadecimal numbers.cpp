//this code is working perfectly fine in another compiler

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
		else if(s[i]>='A' && s[i]<='F')
		{
			dec+=(s[i]-55)*base;
			base*=16;
		}
	}
	return dec;
}
/*
void  DecToHex(int a[], char hexa[][10], int n)
{
	int temp,hi=0,j,k=0,di,hj=0;
	hexa[n][10];
	for(di=0;di<n;di++)
	{
		while(a[di]!=0)
		{
			temp=0;
			temp=a[di]%16;
		
			if(temp<10)
			{
				hexa[hi][hj]=temp+48;
				++hj;
			}
			else
			{
				hexa[hi][hj]=temp+55;
				++hj;
			}
			a[di]=a[di]/16;
		}
		hi+=1;
	}
	for(j=0;j<n;j++)
	{
		printf("%s\n",hexa[j]);
	}
}
*/
void  DecToHex(int n)
{
	int temp,i=0,j;
	char hexa[10];
	while(n!=0)
	{
		temp=0;
		temp=n%16;
		
		if(temp<10)
		{
			hexa[i]=temp+48;
			++i;
		}
		else
		{
			hexa[i]=temp+55;
			++i;
		}
		n=n/16;
	}
	for(j=i;j>=0;j--)
	{
		printf("%c",hexa[j]);
	}
	printf("\n");
}

int max_ele(int a[], int n)
{
	int i;
	int max=a[0];
	for(i=0;i<n;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	return max;
}


void count_sort(int a[], int n, int pos)
{
	int count[10]={0};
	int cpy[n],i;
	for(i=0;i<n;i++)
	{
		++count[(a[i]/pos)%10];
	}
	for(i=1;i<10;i++)
	{
		count[i]+=count[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		cpy[--count[(a[i]/pos)%10]]=a[i];
	}
	for(i=0;i<n;i++)
	{
		a[i]=cpy[i];
	}
}


void redix(int a[], int n)
{
	int i,pos;
	int max=max_ele(a,n);
	for(pos=1;max/pos>0;pos*=10)
	{
		count_sort(a,n,pos);
	}
}


int main()
{
	int decimal[20];
	int i,n,res;
	printf("enter number of words:");
	scanf("%d",&n);
	char s[n][10];
	for(i=0;i<n;i++)
	{
		printf("enter word:");
		scanf("%s",s[i]);
	}
	
	for(i=0;i<n;i++)
	{
		res=HexToDec(s[i]);
		decimal[i]=res;
	}
	
/*	for(i=0;i<n;i++)
	{
		printf("%d\n",decimal[i]);
	}  */
	
	redix(decimal,n);
	
/*	for(i=0;i<n;i++)
	{
		printf("%d\n",decimal[i]);
	}  */
	
	for(i=0;i<n;i++)
	{
		DecToHex(decimal[i]);	
	}
	
//	DecToHex(decimal,s,n);
	
	return 0;
}

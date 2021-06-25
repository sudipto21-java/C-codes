#include<stdio.h>

void copy_elements(int a[], int b[], int c[], int n)
{
	for(int i=0;i<n;i++)
	{
		b[i]=c[i]=a[i];
	}
}

void arr_rotation_1(int a[], int n, int k)	// time O(n) , space O(k)
{
	int temp[k],i,j;
	
	for(i=0;i<k;i++)
	{
		temp[i]=a[i];
	}
	
	for(i=0;i<n-k;i++)
	{
		a[i]=a[i+k];
	}
	
	for(j=0;i<n && j<k;i++,j++)
	{
		a[i]=temp[j];
	}
}

void arr_rotation_2(int b[], int n, int k)
{
	int i,temp;
	
	while(k>0)	// time O(n*k) , space O(1)
	{
		i=0;
		temp=b[i];
		for(i=0;i<n-1;i++)
		{
			b[i]=b[i+1];
		}
		b[n-1]=temp;
		k--;
	}
}

int gcd(int a, int b)
{
	if(a==0)
		return b;
	if(a>b)
		gcd(a-b,b);
	else
		gcd(b-a,a);
}

void arr_rotation_juggling_algo(int c[], int n, int k)		// time O(n) , space O(1)
{
	int hcf=gcd(n,k),i,j=0,temp;	// not valid when hcf is 1
	
	while(k>0)
	{
		temp=c[j];
		for(i=j;i<n;i+=hcf)
		{
			c[i]=c[i+hcf];
		}
		c[i-hcf]=temp;
		j++,k--;	
	}
}

void print_arr(int a[], int n)
{
	int i;
	printf("\nafter rotation\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}

int main()
{
	int i,n,k;
	
	printf("enter size of array:");
	scanf("%d",&n);
	
	int a[n], b[n], c[n];
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&a[i]);
	}
	
	copy_elements(a,b,c,n);
	
	printf("enter the value on which you wanna rotate array:");
	scanf("%d",&k);
	
	arr_rotation_1(a,n,k);
	print_arr(a,n);
	
	arr_rotation_2(b,n,k);
	print_arr(b,n);
	
	arr_rotation_juggling_algo(c,n,k);
	print_arr(c,n);
	
	return 0;
}

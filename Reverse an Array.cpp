#include<stdio.h>

void copy_elements(int a[], int b[], int c[], int n)
{
	for(int i=0;i<n;i++)
	{
		b[i]=c[i]=a[i];
	}
}

void reverse_using_space(int a[], int n)		// time O(n) , space O(n)
{
	int temp[n],i,j;
	
	for(i=n-1,j=0;i>=0;i--,j++)
	{
		temp[j]=a[i];
	}
	
	for(i=0;i<n;i++)
	{
		a[i]=temp[i];
	}
}

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void reverse(int b[], int n)		// time O(n) , space O(1)
{
	int start,end;
	
	for(start=0,end=n-1;start<=end;start++,end--)
	{
		swap(&b[start],&b[end]);
	}
}

void reverse_using_recursion(int c[], int start, int end)		// time O(n) , space O(1)
{
	if(start>=end)
		return;
		
	swap(&c[start],&c[end]);
	reverse_using_recursion(c,start+1,end-1);
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
	
	reverse_using_space(a,n);
	print_arr(a,n);
	
	reverse(b,n);
	print_arr(b,n);
	
	reverse_using_recursion(c,0,n-1);
	print_arr(c,n);
	
	return 0;
}

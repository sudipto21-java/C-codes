#include<stdio.h>
#include<math.h>

void copy_temp_into_main_arr(int temp[], int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		a[i]=temp[i];
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}

void reverse_array_in_groups(int a[], int n, int k)
{
	int temp[n],i,j=k;
	
	for(i=0;i<k && i<n;i++)
	{
		if(i==k-1 && i<n)
			k+=i;
			
		temp[j-1]=a[i];
		
		if(abs(i-j)==2)
			j=i;
	}
	copy_temp_into_main_arr(temp,a,n);
}

int main()
{
	int n,i,k;
	printf("enter size of array:");
	scanf("%d",&n);
	
	int a[n];
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&a[i]);
	}
	
	printf("enter the group size:");
	scanf("%d",&k);
	reverse_array_in_groups(a,n,k);
	return 0;
}


#include<stdio.h>

void reverse(int a[], int s, int e)
{
    for(int i=s, j=e-1; i<j && i!=j;i++,j--)
    {
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}

void printArr(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}

void rotateArr1(int arr[], int d, int n) 		// time complexity O(n)
{   
    reverse(arr,0,d);
    reverse(arr,d,n);
    reverse(arr,0,n);
}

void rotateArr2(int arr[], int d, int n) { 		// time complexity O(n*d)
	
	int t,i,j;
	
	while(d>0) {
		
		t=arr[0];
		for(i=1,j=0;i<n;i++,j++) {
			
			arr[j]=arr[i];
		}
		
		arr[j]=t;
		d--;
	}
}

int main()
{
	int n,i,d;
	printf("enter size of array:");
	scanf("%d",&n);
	
	int a[n];
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&a[i]);
	}
	
	printf("enter a value by which you wanna rotate array:");
	scanf("%d",&d);
	
	rotateArr1(a,d,n);
	printArr(a,n);
	
	printf("\n");
	
	rotateArr2(a,d,n);
	printArr(a,n);
	
	return 0;
}

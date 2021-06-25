#include<bits/stdc++.h>

void getPrimes(int n)
{
	bool primes[n];
	memset(primes,true,sizeof(primes));
	
	for(int p=2;p*p<=n;p++)    // time complexity is O(n*loglogn);
	{
		if(primes[p]==true)
		{
			for(int i=p*p;i<=n;i+=p)
			{
				primes[i]=false;
			}
		}
	}
	
	for(int p=2;p<=n;p++)
	{
		if(primes[p]==true)
			printf("%d ",p);
	}
}

int main()
{
	int n;
	printf("enter a number untill which you wanna get primes\n");
	scanf("%d",&n);
	getPrimes(n);
	return 0;
}

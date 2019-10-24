#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int isprime[1000005];
int sieve()
{
	for (int i=2;i<1000005;i++)
	{
		if (isprime[i]==0)
		{
			for (int j=i*2;j<1000005;j+=i)
			{
				isprime[j]=1;
			}
		}
	}
}
long long gcd(int a,int b)
{
	int rem=1;
	while (rem>0)
	{
		rem=a%b;
		a=b;
		b=rem;
	}
	return a;
}
int main()
{
	sieve();
	while (1<2)
	{
		long long int n;
		cin>>n;
		if (n==0)break;
		long long int rem=1;
		long long int ram;
		for (int i=2;i<1000005;i++)
		{
			if (i>n)break;
			if (isprime[i]==0&&i<=n)
			{
				ram=i;
				while (ram<=n)
				{
					ram*=i;
				}
				ram/=i;
				rem*=ram%1000000000;
				while (rem%10==0)
				{
					rem/=10;
				}
				rem%=1000000000;
			}
		}
		printf ("%lld\n",rem%10);
	}
}
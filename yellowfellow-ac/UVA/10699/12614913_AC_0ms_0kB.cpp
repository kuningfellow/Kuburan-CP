#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool isprime[1005];
int primes[1000];
int siz;
void sieve()
{
	for (int i=2;i<1005;i++)
	{
		if (isprime[i]==0)
		{
			primes[siz++]=i;
			for (int j=i*2;j<1005;j+=i)
			{
				isprime[j]=1;
			}
		}
	}
}
int main()
{
	sieve();
	while (1<2)
	{
		int n;
		cin>>n;
		if (n==0)break;
		int sav=n;
		int i=0;
		int cou=0;
		while (n>0&&i<siz)
		{
			if (primes[i]*primes[i]>n)break;
			if (n%primes[i]==0)
			{
				cou++;
				while (n%primes[i]==0)
				{
					n/=primes[i];
				}
			}
			i++;
		}
		if (n>1)cou++;
		printf ("%d : %d\n",sav,cou);
	}
}
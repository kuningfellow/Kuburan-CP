#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool isprime[10000];
int lis[5000005];
int siz;
void sieve()
{
	for (int i=2;i<10000;i++)
	{
		if (isprime[i]==0)
		{
			lis[siz++]=i;
			for (int j=i*2;j<10000;j+=i)
			{
				isprime[j]=1;
			}
		}
	}
}
bool segsiv[1000000];
int sta;
void segify(int l)
{
	for (int i=0;i<siz;i++)
	{
		if (i*i>l+1000000)break;
		sta=(l/lis[i]*lis[i])+lis[i]*(l%lis[i]>0)-l;
		if (l<10000&&isprime[l]==0)
		{
			sta+=lis[i];
		}
		for (int j=sta;j<1000000;j+=lis[i])
		{
			segsiv[j]=1;
		}
	}
	for (int i=0;i<1000000;i++)
	{
		if (segsiv[i]==0&&siz<5000005)
		{
			lis[siz++]=i+l;
		}
		segsiv[i]=0;
	}
}
int main()
{
	sieve();
	for (int i=10000;i<90000000;i+=1000000)
	{
		segify(i);
	}
	int tc;
	cin>>tc;
	while (tc--)
	{
		int n;
		cin>>n;
		printf ("%d\n",lis[n-1]);
	}
}
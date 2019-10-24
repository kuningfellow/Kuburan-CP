#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while (tc--)
	{
		long long int rem;
		cin>>rem;
		long long int ram=0;
		long long int temp=rem;
		long long int a;
		int i=0;
		while (1<2)
		{
			i++;
			rem=temp;
			ram=0;
			while (rem>0)
			{
				ram*=10;
				ram+=rem%10;
				rem/=10;
			}
			temp+=ram;
			a=0;
			rem=temp;
			while (rem>0)
			{
				a*=10;
				a+=rem%10;
				rem/=10;
			}
			if (a==temp)break;
		}
		printf ("%d %lld\n",i,temp);
	}
}
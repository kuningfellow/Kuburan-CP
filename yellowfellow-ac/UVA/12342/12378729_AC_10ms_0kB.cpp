//UVA 12342 Tax Calculator
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int tc,kas=1;
	cin>>tc;
	while (tc--)
	{
		long long int n;
		long long int pay=0;
		cin>>n;
		n-=180000;
		if (n>0)
		{
			if (n>300000)
				pay+=3000000;
			else if (n>0)
				pay+=10*n;
			n-=300000;
			if (n>400000)
				pay+=400000*15;
			else if (n>0)
				pay+=n*15;
			n-=400000;
			if (n>300000)
				pay+=300000*20;
			else if (n>0)
				pay+=n*20;
			n-=300000;
			if (n>0)
				pay+=n*25;
			n=0;
			if (pay<200000)pay=200000;
			if (pay%100>0)
				pay=pay/100+1;
			else pay=pay/100;
		}
		printf ("Case %d: %lld\n",kas++,pay);
	}
}
//UVA 11185 Ternary
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	long long int n;
	while (1<2)
	{
		cin>>n;
		if (n<0)break;
		vector<long long int>num;
		while (n>0)
		{
			num.push_back(n%3);
			n/=3;
		}
		for (int i=num.size()-1;i>=0;i--)
		{
			printf ("%lld",num[i]);
		}
		if (num.size()==0)printf ("0");
		printf ("\n");
		num.clear();
	}
}
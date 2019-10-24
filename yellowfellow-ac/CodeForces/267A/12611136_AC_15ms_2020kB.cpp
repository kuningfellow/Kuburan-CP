#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		long long int a,b;
		cin>>a>>b;
		long long int step=0;
		long long int tem;
		while (a!=0&&b!=0)
		{
			if (a>=b)
			{
				tem=(a/b);
				a-=tem*b;
				step+=tem;
			}
			else
			{
				tem=(b/a);
				b-=tem*a;
				step+=tem;
			}
		}
		printf ("%lld\n",step);
	}
}
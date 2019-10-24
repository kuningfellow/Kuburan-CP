#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	int rem=0;
	while (b>0)
	{
		rem=a%b;
		a=b;
		b=rem;
	}
	return a;
}
int main()
{
	int tc;
	cin>>tc;
	while (tc--)
	{
		int a, b;
		cin>>a>>b;
		int c=gcd(a,b);
		c=gcd(a,c);
		c=a/c;
		if (c<a)
		{
			printf ("No %d\n",c);
		}
		else printf ("Yes\n");
	}
}
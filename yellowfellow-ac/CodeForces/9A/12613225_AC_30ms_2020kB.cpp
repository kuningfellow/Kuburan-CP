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
	int a, b;
	cin>>a>>b;
	a=max(a,b);
	int res=6-a+1;
	printf ("%d/%d\n",res/gcd(res,6),6/gcd(res,6));
}
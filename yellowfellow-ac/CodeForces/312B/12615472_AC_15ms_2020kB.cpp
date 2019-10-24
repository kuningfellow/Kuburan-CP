#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
double pow(double a, int b)
{
	double ret=1;
	double mul=a;
	while (b>0)
	{
		if (b%2==1)
		{
			ret*=mul;
		}
		mul*=mul;
		b/=2;
	}
	return ret;
}
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	double init=(double)a/b;
	a=b-a;
	c=d-c;
	int rem=a*c;
	int ram=b*d;
	double ex=(double)rem/ram;
	double res=init;
	for (int i=1;i<10000;i++)
	{
		res+=(double)init*pow(ex,i);
	}
	printf ("%f\n",res);
}
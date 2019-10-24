#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
	double a,b,c;
	while (scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
	{
		double l=sqrt((a+b+c)/2*(b+c-a)/2*(a+b-c)/2*(a+c-b)/2);
		double r=2*l/(a+b+c);
		double R=a*b*c/4/l;
		printf ("%.4f %.4f %.4f\n",R*R*2*acos(0)-l,l-r*r*2*acos(0),r*r*2*acos(0));
	}
}
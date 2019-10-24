#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        double x,y;
        cin>>x>>y;
        x/=4;
        y/=2;
        double a=(x*2+sqrt(4*x*x-12*y))/6;
        double b=(x*2-sqrt(4*x*x-12*y))/6;
        printf ("%.2f\n",max((x-2*a)*a*a,(x-2*b)*b*b));
    }
}

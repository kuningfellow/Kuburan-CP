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
        double l=0,r=min(a,b),mid,ans,rem;
        for (int i=0;i<1000;i++)
        {
            mid=(l+r)/2;
            rem=(sqrt(a*a-mid*mid)*(1-(c/(sqrt(b*b-mid*mid)))))-c;
            if (rem<0)
            {
                ans=mid;
                r=mid;
            }
            else
                l=mid;
        }
        printf ("%.3f\n",ans);
    }
}
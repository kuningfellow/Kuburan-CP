#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        double a,b;
        cin>>a>>b;
        double ar=a*2*b;
        double ir=0;
        if (b*4>=a)
        {
            ir=a*(a/4)/2;
        }
        else
        {
            ir=b*(b*4)/2+(a-(b*4))*b;
        }
        ir+=a*b;
        if (a<1e-9&&b<1e-9)printf ("%.10f\n",(double)1);
        else if (a<1e-9)printf("%.10f\n",(double)0.5);
        else if (b<1e-9)printf ("%.10f\n",(double)1);
        else printf ("%.10f\n",ir/ar);
    }
}

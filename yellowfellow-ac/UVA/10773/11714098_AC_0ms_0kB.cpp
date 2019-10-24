//UVA 10773 Back to Intermediate Math
#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    int kase=1;
    double fast,shor,a,b,c;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        fast=a/c;
        shor=c*c-b*b;
        printf ("Case %d: ",kase++);
        if (shor<=0)printf ("can't determine\n");
        else
        {
            shor=a/sqrt(shor);
            if (shor-fast<1e-9)printf ("can't determine\n");
            else printf ("%.3f\n",shor-fast);
        }
    }
}

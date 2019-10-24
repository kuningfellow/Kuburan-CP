#include <stdio.h>
#include <cmath>
int main()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        int i;
        scanf("%d",&i);
        double a,b,c;
        a=i;
        b=(double)6*i/10;
        c=(double)i/5;
        double cir=c*c*acos(-1);
        printf ("%.2f %.2f\n",cir,a*b-cir);
        t--;
    }
    return 0;
}

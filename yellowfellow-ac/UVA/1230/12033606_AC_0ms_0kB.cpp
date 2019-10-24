//UVA 1230 MODEX
#include <stdio.h>
int main()
{
    int tc,a,b,c,d=1;
    scanf("%d",&tc);
    while (tc--)
    {
        d=1;
        scanf("%d%d%d",&a,&b,&c);
        while (b>0)
        {
            if (b%2==1)
            {
                d*=a;
                d%=c;
            }
            a*=a;
            a%=c;
            b/=2;
        }
        printf ("%d\n",d);
    }
    scanf("%d",&a);
}

#include <stdio.h>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int c=a+b;
    int x=0,y=0,z=0;
    int mul=1;
    while (a>0)
    {
        if (a%10!=0)
        {
            x+=mul*(a%10);
            mul*=10;
        }
        a/=10;
    }
    mul=1;
    while (b>0)
    {
        if (b%10!=0)
        {
            y+=mul*(b%10);
            mul*=10;
        }
        b/=10;
    }
    mul=1;
    while (c>0)
    {
        if (c%10!=0)
        {
            z+=mul*(c%10);
            mul*=10;
        }
        c/=10;
    }
    if (x+y==z)printf ("YES\n");
    else printf ("NO\n");
    return 0;
}

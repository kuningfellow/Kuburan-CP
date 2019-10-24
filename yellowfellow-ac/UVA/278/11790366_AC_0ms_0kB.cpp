//UVA 278 Chess
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        char c[5];
        int m,n;
        scanf("%s%d%d",&c,&m,&n);
        if (c[0]=='r')
        {
            printf ("%d\n",m>n?n:m);
            continue;
        }
        else if (c[0]=='k')
        {
            int a=(m/2)*n;
            int b=(n/2)*m;
            printf ("%d\n",a>b?a:b);
        }
        else if (c[0]=='Q')
        {
            printf ("%d\n",m>n?n:m);
        }
        else if (c[0]=='K')
        {
            printf ("%d\n",(m/2+(m%2>0))*(n/2+(n%2>0)));
        }
    }
}

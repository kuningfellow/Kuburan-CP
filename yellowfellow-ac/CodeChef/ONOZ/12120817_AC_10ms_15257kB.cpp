#include <stdio.h>
#include <iostream>
using namespace std;
int bac=1;
int good(int a, int b)
{
    int ret=1;
    int sel=a%10;
    while (a>0)
    {
        if (a%10!=sel)
        {
            ret=0;
        }
        a/=10;
    }
    int co=0;
    if (b%10!=sel)ret=0;
    while (b>0)
    {
        if (b%10!=sel)
        {
            ret=0;
        }
        b/=10;
    }
    return ret;
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a;
        b;
        int co=0;
        for (int i=0;i<a;i++)
        {
            for (int j=0;j<b;j++)
            {
                if (good(i,j))
                {
                    co++;
                }
            }
        }
        printf ("%d\n",co);
    }
}

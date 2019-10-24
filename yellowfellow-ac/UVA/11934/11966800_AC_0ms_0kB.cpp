//UVA 11934 Magic Formula
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    while (1<2)
    {
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        if (a==0&&b==0&&c==0&&d==0&&e==0)break;
        int co=0;
        for (int i=0;i<=e;i++)
        {
            if ((a*i*i+b*i+c)%d==0)co++;
        }
        printf ("%d\n",co);
    }
}

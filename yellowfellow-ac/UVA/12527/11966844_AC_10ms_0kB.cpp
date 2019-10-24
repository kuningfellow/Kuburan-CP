//UVA 12527 Different Digits
#include <stdio.h>
#include <iostream>
using namespace std;
int rep(int i)
{
    int co[10];
    for (int i=0;i<10;i++)co[i]=0;
    while (i>0)
    {
        co[i%10]++;
        if (co[i%10]>1)return 0;
        i/=10;
    }
    return 1;
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int co=0;
        for (int i=n;i<=m;i++)
        {
            if (rep(i))co++;
        }
        printf ("%d\n",co);
    }
}

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
long long int sum[100005];
long long int dive[100005];
long long int fin (int a)
{
    if (sum[a]>0)
        return sum[a];
    int tem=0;
    int d=0;
    for (int i=1;i*i<=a;i++)
    {
        if (a%i==0)
        {
            if (i*i!=a)
            {
                d+=2;
                tem+=i+(a/i);
            }
            else
            {
                tem+=i;
                d++;
            }
        }
    }
    sum[a]=tem;
    dive[a]=d;
    return sum[a];
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        long long int res=0;
        long long int ras=0;
        for (int i=a;i<=b;i++)
        {
            if (i%c==0)
            {
                res+=fin(i);
                ras+=dive[i];
            }
        }
        printf ("%lld %lld\n",ras,res);
    }
}

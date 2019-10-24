#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
long long int func(long long int a, long long int b)
{
    long long int res=1;
    long long int l;
    l=min(b,(a-b));
    b=max(b,(a-b));
    for (int i=a;i>b;i--)
    {
        res*=i;
        if ((a-i+1)<=l)
        {
            res/=(a-i+1);
        }
    }
//    for (int i=1;i<=l;i++)
//    {
//        res/=i;
//    }
    return res;
}
int main()
{
    while (1<2)
    {
        long long int a,b;
        cin>>a>>b;
        if (a==0&&b==0)break;
        printf ("%lld\n",func(a,b));
    }
}

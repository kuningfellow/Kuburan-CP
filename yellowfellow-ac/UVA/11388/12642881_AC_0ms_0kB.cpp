#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b)
{
    int rem;
    while (b>0)
    {
        rem=a%b;
        a/=b;
        b=rem;
    }
    return a;
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        long long int n,m;
        cin>>n>>m;
        if (m%n>0)printf ("-1\n");
        else
        {
            printf ("%lld %lld\n",n,m);
        }
    }
}

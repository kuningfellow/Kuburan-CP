#include <stdio.h>
#include <iostream>
using namespace std;
long long int gcd(long long int a, long long int b)
{
    long long int rem=1;
    while (rem>0)
    {
        rem=a%b;
        a=b;
        if (rem==0)break;
        b=rem;
    }
    return b;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        long long int n,m;
        cin>>n>>m;
        long long int cak;
        if (m==0)cak=1;
        else cak=n/gcd(n,m);
        if (cak<n)
        {
            printf ("No %lld\n",cak);
        }
        else printf ("Yes\n");
    }
}

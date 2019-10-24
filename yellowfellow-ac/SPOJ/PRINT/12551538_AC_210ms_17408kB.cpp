#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool isprime[(1<<17)];
vector<int>lis;
void sieve()
{
    for (int i=2;i<(1<<17);i++)
    {
        if (isprime[i]==0)
        {
            lis.push_back(i);
            for (int j=i*2;j<(1<<17);j+=i)
            {
                isprime[j]=1;
            }
        }
    }
}
bool segsiv[2000000];
int main()
{
    sieve();
    int tc;
    cin>>tc;
    while (tc--)
    {
        long long int a,b;
        cin>>a>>b;
        long long int l=b-a+1;
        for (long long int i=0;i<l;i++)
        {
            segsiv[i]=0;
        }
        long long int sta;
        for (long long int i=0;i<lis.size();i++)
        {
            if (lis[i]>b)break;
            sta=a/lis[i]*lis[i]+lis[i];
            if (a%lis[i]==0)sta=a/lis[i]*lis[i];
            if (sta<(1<<17)&&isprime[sta]==0)
            {
                sta+=lis[i];
            }
            for (long long int j=sta;j<=b;j+=lis[i])
            {
                segsiv[j-a]=1;
            }
        }
        for (long long int i=0;i<l;i++)
        {
            if (segsiv[i]==0&&i+a!=1)
            {
                printf ("%lld\n",i+a);
            }
        }
    }
}

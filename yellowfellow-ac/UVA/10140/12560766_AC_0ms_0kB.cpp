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
int main()
{
    sieve();
    bool segsiv[1000005];
    long long int a,b;
    while (scanf("%lld%lld",&a,&b)!=EOF)
    {
        for (int i=0;i<=(b-a);i++)
        {
            segsiv[i]=0;
        }
        long long int smal=((long long)1<<32);
        long long int big=0;
        int sta=0;
        for (int i=0;i<lis.size();i++)
        {
            if (lis[i]*lis[i]>b)break;
            sta=(a/lis[i]*lis[i]+lis[i]*(a%lis[i]>0))-a;
            if (sta+a<(1<<17)&&isprime[sta+a]==0)
                sta+=lis[i];
            for (int j=sta;j<=(b-a);j+=lis[i])
            {
                segsiv[j]=1;
            }
        }
        int c1=-1,c2=-1,d1=-1,d2=-1;
        int rem=-1,ram=-1;
        int co=0;
        for (int i=0;i<=(b-a);i++)
        {
            if (segsiv[i]==1||i+a==0||i+a==1)continue;
            if (segsiv[i]==0)co++;
            if (rem!=i&&segsiv[i]==0)
            {
                if (rem!=-1&&i-rem<smal)
                {
                    smal=i-rem;
                    c1=rem;
                    c2=i;
                }
                rem=i;
            }
            if (ram!=i&&segsiv[i]==0)
            {
                if (ram!=-1&&i-ram>big)
                {
                    big=i-ram;
                    d1=ram;
                    d2=i;
                }
                ram=i;
            }
        }
        if (co<2)printf ("There are no adjacent primes.\n");
        else printf ("%lld,%lld are closest, %lld,%lld are most distant.\n",c1+a,c2+a,d1+a,d2+a);
    }
}

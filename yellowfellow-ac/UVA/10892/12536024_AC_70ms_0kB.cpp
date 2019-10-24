#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool isprime[1000000];
vector<int>primes;
int siev()
{
    for (int i=2;i<1000000;i++)
    {
        if (isprime[i]==0)
        {
            primes.push_back(i);
            for (int j=i*2;j<1000000;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
}
long long int serc(long long int a)
{
    long long int temp=a;
    long long int way=1;
    int co=0;
    for (int i=0;i<primes.size();i++)
    {
        if (temp%primes[i]==0&&temp>0)
        {
            co=0;
            while (temp%primes[i]==0&&temp>0)
            {
                co++;
                temp/=primes[i];
            }
            way*=2*co+1;
        }
    }
    return way;
}
int main()
{
    siev();
    while (1<2)
    {
        long long int n;
        cin>>n;
        if (n==0)break;
        printf ("%lld %lld\n",n,serc(n)/2+1);
    }
}

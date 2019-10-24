#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool isprime[10000005];
vector<long long int>lis;
void siev()
{
    for (long long int i=2;i<10000005;i++)
    {
        if (isprime[i]==0)
        {
            lis.push_back(i);
            for (long long int j=i*2;j<10000005;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
}
long long fac(long long int a)
{
    int co=0;
    long long int rem=0;
    for(int i=0;i<lis.size();i++)
    {
        if (a>0&&a%lis[i]==0)
        {
            co++;
            while (a>0&&a%lis[i]==0)
            {
                a/=lis[i];
            }
            rem=lis[i];
        }
        if (a==0)break;
    }
    if (a>1)co++;
    if (co<2)return -1;
    if (a>rem)rem=a;
    return rem;
}
int main()
{
    siev();
    while (1<2)
    {
        long long int n;
        cin>>n;
        n=abs(n);
        if (n==0)break;
        printf ("%lld\n",fac(n));
    }
}

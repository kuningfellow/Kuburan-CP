#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
bool isprime[1000005];
vector<int>lis;
int dp[1000005];
int sum[1000005];
void sieve()
{
    for (int i=2;i<1000005;i++)
    {
        if (isprime[i]==0)
        {
            lis.push_back(i);
            for (int j=i*2;j<1000005;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
}
int siz;
int fun(int a)
{
    if (isprime[a]==0)return -1;
    int ret=1;
    int co=0;
    int m=0;
    for (int i=0;i<siz;i++)
    {
        if (lis[i]*lis[i]>a)break;
        co=0;
        if (a%lis[i]==0)
        {
            m++;
        }
        while (a%lis[i]==0)
        {
            a/=lis[i];
            co++;
        }
        if (co>1)
        {
            ret=0;
        }
    }
    if (a>1)m++;
    if (ret==1&&m%2==0)
    {
        return 1;
    }
    else if (ret==1&&m%2==1)
    {
        return -1;
    }
    return 0;
}
int main()
{
    sieve();
    siz=lis.size();
    dp[1]=1;
    sum[1]=1;
    for (int i=2;i<1000000;i++)
    {
        dp[i]=fun(i);
        sum[i]=dp[i]+sum[i-1];
    }
    while (1<2)
    {
        int n;
        cin>>n;
        if (n==0)break;
        printf ("%8d%8d%8d\n",n,dp[n],sum[n]);
    }
}

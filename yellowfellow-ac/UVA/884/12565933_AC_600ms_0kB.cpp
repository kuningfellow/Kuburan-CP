#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool isprime[1005];
int dp[1000005];
vector<int>lis;
void sieve()
{
    for (int i=2;i<1005;i++)
    {
        if (isprime[i]==0)
        {
            lis.push_back(i);
            for (int j=i*2;j<1005;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
}
int fac(int a)
{
    int ret=0;
    int sav=a;
    for (int i=0;i<lis.size();i++)
    {
        while (a>0&&a%lis[i]==0)
        {
            ret++;
            a/=lis[i];
        }
    }
    if (a>1)return dp[sav]=ret+1;
    return dp[sav]=ret;
}
int main()
{
    sieve();
    dp[1]=0;
    for (int i=2;i<1000005;i++)
    {
        fac(i);
        dp[i]+=dp[i-1];
    }
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        printf ("%d\n",dp[n]);
    }
}

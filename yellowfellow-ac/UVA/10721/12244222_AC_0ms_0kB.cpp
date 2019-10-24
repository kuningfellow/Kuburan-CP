//UVA 10721 Bar Codes
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
long long int dp[55][55][55];
long long int serc(int n, int k,int step)
{
    if (n==0&&k==0)
    {
        return 1;
    }
    if (n<0)
    {
        return 0;
    }
    if (dp[n][k][step]!=-1)
    {
        return dp[n][k][step];
    }
    long long int ret=0;
    if (k>0)
    {
        for (int i=1;i<=step;i++)
        {
            ret+=serc(n-i,k-1,step);
        }
    }
    return dp[n][k][step]=ret;
}
int main()
{
    for (int i=0;i<55;i++)
    {
        for (int j=0;j<55;j++)
        {
            for (int k=0;k<55;k++)
            {
                dp[i][j][k]=-1;
            }
        }
    }
    int n,m,k;
    while (scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        printf ("%lld\n",serc(n,m,k));
    }
}

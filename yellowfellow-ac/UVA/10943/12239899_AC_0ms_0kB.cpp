//UVA 10943 How do you add?
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int dp[105][105];
int serc(int n, int k)
{
    int ret=0;
    if (dp[n][k]!=-1)
    {
        return dp[n][k];
    }
    if (k==1||n==0)
    {
        return dp[n][k]=1;
    }
    for (int i=0;i<=n;i++)
    {
        ret+=serc(n-i,k-1);
        ret%=1000000;
    }
    return dp[n][k]=ret%1000000;
}
int main()
{
    for (int i=0;i<105;i++)
    {
        for (int j=0;j<105;j++)
        {
            dp[i][j]=-1;
        }
    }
    serc(104,104);
    while (1<2)
    {
        int n,m;
        cin>>n>>m;
        if (n==0&&m==0)break;
        printf ("%d\n",dp[n][m]);
    }
}

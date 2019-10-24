//UVA 10446 The Marriage Interview :-)
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
unsigned long long int dp[65][65];
unsigned long long int func(int n, int k)
{
    if (n==1)return dp[n][k]=1;
    if (n<=1)return 1;
    if (dp[n][k]!=-1)
    {
        return dp[n][k];
    }
    dp[n][k]=1;
    for (int i=1;i<=k;i++)
    {
        dp[n][k]+=func(n-i,k);
    }
    return dp[n][k];
}
int main()
{
    for (int i=0;i<=60;i++)
    {
        for (int j=0;j<=60;j++)
        {
            dp[i][j]=-1;
        }
    }
    for (int i=0;i<=60;i++)
    {
        dp[i][0]=1;
        dp[0][i]=1;
    }
    for (int i=0;i<=60;i++)
    {
        func(60,i);
    }
    int kas=1;
    while (1<2)
    {
        int a,b;
        cin>>a>>b;
        if (a>60)break;
        printf ("Case %d: %llu\n",kas++,func(a,b));
    }
}

//UVA 11407 Squares
//top down
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int dp[10005];
int serc(int n)
{
    if (n==0)return 0;
    if (dp[n]!=-1)
    {
        return dp[n];
    }
    int ret=10000;
    for (int i=1;i*i<=n;i++)
    {
        ret=min(ret,1+serc(n-i*i));
    }
    return dp[n]=ret;
}
int main()
{
    for (int i=0;i<10005;i++)
    {
        dp[i]=-1;
    }
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        printf ("%d\n",serc(n));
    }
}

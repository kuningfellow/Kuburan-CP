//UVA 10036 Divisibility
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n;
int m;
int ar[10005];
int dp[10005][105];
int serc(int x, int rem)
{
    while (rem<0)
    {
        rem+=m;
    }
    if (x==n&&rem==0)
    {
        return 1;
    }
    if (x==n)
    {
        return 0;
    }
    if (dp[x][rem]!=-1)
    {
        return dp[x][rem];
    }
    dp[x][rem]=0;
    dp[x][rem]=max(dp[x][rem],serc(x+1,(rem+ar[x]+m)%m));
    dp[x][rem]=max(dp[x][rem],serc(x+1,(rem-ar[x]+m)%m));
    return dp[x][rem];
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        cin>>n>>m;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                dp[i][j]=-1;
            }
        }
        for (int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        if (serc(0,0))
        {
            printf ("Divisible\n");
        }
        else
        {
            printf ("Not divisible\n");
        }
    }
}

//UVA 11407 Squares
//bottom up
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int dp[10005];
int main()
{
    for (int i=0;i<10005;i++)
    {
        dp[i]=100000;
    }
    for (int i=0;i<=100;i++)
    {
        dp[i*i]=1;
    }
    for (int i=0;i<10005;i++)
    {
        for (int j=0;j*j<=i;j++)
        {
            dp[i]=min(dp[i],dp[i-j*j]+1);
        }
    }
    int tc;
    cin>>tc;
    int n;
    while (tc--)
    {
        cin>>n;
        printf ("%d\n",dp[n]);
    }
}

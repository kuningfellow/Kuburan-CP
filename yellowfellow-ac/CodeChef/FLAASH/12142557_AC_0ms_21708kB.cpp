#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int dp[1000005];
int serc(int s)
{
    if (s==0)return 0;
    if (dp[s]!=1000005)return dp[s];
    dp[s]=min(dp[s],1+serc(s-1));
    if (s%2==0)
    {
        dp[s]=min(dp[s],1+serc(s/2));
    }
    if (s%3==0)
    {
        dp[s]=min(dp[s],1+serc(s/3));
    }
    return dp[s];
}
int main()
{
    int tc;
    cin>>tc;
    for (int i=0;i<1000005;i++)
    {
        dp[i]=1000005;
    }
    while (tc--)
    {
        int n;
        scanf("%d",&n);
        printf ("%d\n",serc(n)-1);
    }
}

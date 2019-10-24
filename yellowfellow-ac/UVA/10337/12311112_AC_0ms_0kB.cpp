//UVA 10337 Flight Planner
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int ar[10][1005];
int dp[10][1005];
int d;
int serc(int h, int x)
{
    if (x==d&&h==0)return 0;
    if (x==d&&h!=0)return (1<<30);
    if (dp[h][x]!=-1)
    {
        return dp[h][x];
    }
    dp[h][x]=(1<<30);
    dp[h][x]=min(dp[h][x],30+serc(h,x+1));
    if (h>0)
        dp[h][x]=min(dp[h][x],20+serc(h-1,x+1));
    if (h<9)
        dp[h][x]=min(dp[h][x],60+serc(h+1,x+1));
    dp[h][x]-=ar[h][x];
    return dp[h][x];
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        cin>>d;
        d/=100;
        for (int i=9;i>=0;i--)
        {
            for (int j=0;j<d;j++)
            {
                dp[i][j]=-1;
                scanf("%d",&ar[i][j]);
            }
        }
        printf ("%d\n\n",serc(0,0));
    }
}

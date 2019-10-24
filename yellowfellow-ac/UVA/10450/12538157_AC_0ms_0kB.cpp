#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int n;
long long int dp[53][53][2];
long long int serc(int x,int m)
{
    if (x>=n)return 1;
    if (dp[n][x][m]!=-1)
    {
        return dp[n][x][m];
    }
    long long int ret=0;
    if (m==1)ret=serc(x+1,0);
    else
    {
        ret=serc(x+1,0)+serc(x+1,1);
    }
    return dp[n][x][m]=ret;
}
int main()
{
    for (int i=0;i<53;i++)
    {
        for (int j=0;j<53;j++)
        {
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
    }
    int tc,kas=1;
    cin>>tc;
    while (tc--)
    {
        cin>>n;
        printf ("Scenario #%d:\n%lld\n\n",kas++,serc(0,0));
    }
}

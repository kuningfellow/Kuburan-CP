//UVA 10910 Marks Distribution
//top down
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int dp[75][75][75];
int serc(int n, int t, int p)
{
    if (n==0&&t==0)return 1;
    if (n==0)return 0;
    if (dp[n][t][p]!=-1)return dp[n][t][p];
    int ret=0;
    for (int i=0;i<=t;i++)
    {
        if (i>=p)
            ret+=serc(n-1,t-i,p);
    }
    return dp[n][t][p]=ret;
}
int main()
{
    for (int i=0;i<75;i++)
    {
        for(int j=0;j<75;j++)
        {
            for (int k=0;k<75;k++)
            {
                dp[i][j][k]=-1;
            }
        }
    }
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n,t,p;
        cin>>n>>t>>p;
        cout<<serc(n,t,p)<<endl;
    }
}

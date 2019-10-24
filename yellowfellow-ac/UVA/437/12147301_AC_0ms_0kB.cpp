//UVA 437 The Tower of Babylon
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
vector<int>a[3];
int dp[31][3][3];
int serc(int x, int l, int p)
{
    if (dp[x][l][p]>0)return dp[x][l][p];
    for (int i=0;i<a[0].size();i++)
    {
        if ((a[l][x]>a[0][i]&&a[p][x]>a[1][i]))
        {
            dp[x][l][p]=max(dp[x][l][p],a[2][i]+serc(i,0,1));
        }
        if ((a[l][x]>a[1][i]&&a[p][x]>a[0][i]))
        {
            dp[x][l][p]=max(dp[x][l][p],a[2][i]+serc(i,1,0));
        }
        if ((a[l][x]>a[0][i]&&a[p][x]>a[2][i]))
        {
            dp[x][l][p]=max(dp[x][l][p],a[1][i]+serc(i,0,2));
        }
        if ((a[l][x]>a[2][i]&&a[p][x]>a[0][i]))
        {
            dp[x][l][p]=max(dp[x][l][p],a[1][i]+serc(i,2,0));
        }
        if ((a[l][x]>a[1][i]&&a[p][x]>a[2][i]))
        {
            dp[x][l][p]=max(dp[x][l][p],a[0][i]+serc(i,1,2));
        }
        if ((a[l][x]>a[2][i]&&a[p][x]>a[1][i]))
        {
            dp[x][l][p]=max(dp[x][l][p],a[0][i]+serc(i,2,1));
        }
    }
    return dp[x][l][p];
}
int main()
{
    int kasus=1;
    while (1<2)
    {
        int n;
        cin>>n;
        if (n==0)break;
        int tempa,tempb,tempc;
        a[0].push_back((1<<31)-1);
        a[1].push_back((1<<31)-1);
        a[2].push_back((1<<31)-1);
        for (int i=0;i<n;i++)
        {
            cin>>tempa>>tempb>>tempc;
            a[0].push_back(tempa);
            a[1].push_back(tempb);
            a[2].push_back(tempc);
        }
        for (int i=0;i<=n;i++)
        {
            for (int j=0;j<3;j++)
            {
                for (int k=0;k<3;k++)
                    dp[i][j][k]=0;
            }
        }
        printf ("Case %d: maximum height = ",kasus++);
        cout<<serc(0,0,0)<<endl;
        a[0].clear();
        a[1].clear();
        a[2].clear();
    }
}
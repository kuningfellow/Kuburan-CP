#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
vector<int>bep[2];
int dp[(1<<11)][21][21];
int abs(int a, int b, int x, int y)
{
    a=a-x;
    if (a<0)a=-a;
    b=b-y;
    if (b<0)b=-b;
    return a+b;
}
int xo,yo,n;
int sear(int x,int y, int mask)
{
    if (mask==(1<<n)-1)return abs(x,y,xo,yo);
    if (dp[mask][x][y]!=-1)return dp[mask][x][y];
    for (int i=0;i<n;i++)
    {
        if ((mask&(1<<i))==0)
        {
            if (dp[mask][x][y]==-1)dp[mask][x][y]=abs(x,y,bep[0][i],bep[1][i])+sear(bep[0][i],bep[1][i],(mask|(1<<i)));
            else dp[mask][x][y]=min( dp[mask][x][y],abs(x,y,bep[0][i],bep[1][i]) + sear( bep[0][i], bep[1][i], ( mask|(1<<i) ) ) );
        }
    }
    return dp[mask][x][y];
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        cin>>xo>>yo;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>a>>b;
            bep[0].push_back(a);
            bep[1].push_back(b);
        }
        for (int i=0;i<(1<<11);i++)
        {
            for (int j=0;j<20;j++)
            {
                for (int k=0;k<20;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        cout<<"The shortest path has length "<<sear(xo,yo,0)<<endl;
        bep[0].clear();
        bep[1].clear();
    }
}

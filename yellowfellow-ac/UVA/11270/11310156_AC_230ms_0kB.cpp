#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
using namespace std;
int n,m;
long long int dp[(1<<10)][105][105];
long long int sercx(int mask, int x, int y)
{
    if ((dp[mask][x][y])>=0)
    {
        return dp[mask][x][y];
    }
    if (x==n-1&&y==m-1)
    {
        if ((mask&1)>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    dp[mask][x][y]=0;
    int misk;
    misk=(mask>>1);
    if ((mask&1)>0)
    {
        if (x+1==n)
        {
            dp[mask][x][y]+=sercx(misk,0,y+1);
        }
        else
        {
            dp[mask][x][y]+=sercx(misk,x+1,y);
        }
    }
    else
    {
        if ((misk&1)==0&&(x+1)<n)
        {
            dp[mask][x][y]+=sercx((misk|1),x+1,y);
        }
        if ((misk&(1<<(n-1)))==0&&(y+1)<m)
        {
            if (x+1==n)
            {
                dp[mask][x][y]+=sercx((misk|(1<<(n-1))),0,y+1);
            }
            else
            {
                dp[mask][x][y]+=sercx((misk|(1<<(n-1))),x+1,y);
            }
        }
    }
    return dp[mask][x][y];
}
int main()
{

    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n*m>=101)break;
        int a;
        if (n>m)
        {
            a=m;
            m=n;
            n=a;
        }
        for (int i=0;i<(1<<n);i++)
        {
            for (int j=0;j<m;j++)
                for (int k=0;k<m;k++)
                    dp[i][j][k]=-1;
        }
        cout<<sercx(0,0,0)<<endl;
    }
}

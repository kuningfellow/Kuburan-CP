#include <stdio.h>
#include <iostream>
using namespace std;
int n,m;
int dp[(1<<15)][12][505];
int serc(int mask,int x, int y)
{
    if (x==0&&y==m)
    {
        if (mask==0)return 1;
        else return 0;
    }
    long long int temp=0;
    if (dp[mask][x][y]>=0)
    {
        return dp[mask][x][y];
    }
    dp[mask][x][y]=0;
    if ((mask&1)>0)
    {
        if (x+1==n)
        {
            dp[mask][x][y]+=serc((mask>>1),0,y+1);
            dp[mask][x][y]%=1000000;
        }
        else if (x+1<n)
        {
            dp[mask][x][y]+=serc((mask>>1),x+1,y);
            dp[mask][x][y]%=1000000;
        }
    }
    if (!(mask&1))
    {
        if ( !(mask&2) && !(mask&(1<<n)) && !(mask&(1<<(n+1))) && x+1<n)
        {
            dp[mask][x][y]+=serc( ( ( ( (mask|2)|(1<<n) )|(1<<(n+1)) ) >> 1 ),x+1,y);
            dp[mask][x][y]%=1000000;
        }
        if (!(mask&2) && !(mask&(1<<n)) && x+1<n)
        {
            dp[mask][x][y]+=serc( ( ( (mask|2)|(1<<n) ) >> 1),x+1,y);
            dp[mask][x][y]%=1000000;
        }
        if ( !(mask&(1<<n)) && !(mask&(1<<(n+1))) && x+1<n)
        {
            dp[mask][x][y]+=serc( ( ( (mask|(1<<n))|(1<<(n+1)) ) >> 1 ),x+1,y);
            dp[mask][x][y]%=1000000;
        }
        if ( !(mask&2) && !(mask&(1<<(n+1))) && x+1<n)
        {
            dp[mask][x][y]+=serc( ( ( (mask|2)|(1<<(n+1)) ) >> 1 ),x+1,y);
            dp[mask][x][y]%=1000000;
        }
        if (x-1>=0 && !(mask&(1<<n)) && !(mask&(1<<(n-1))) && x+1<n)
        {
            dp[mask][x][y]+=serc( ( ( (mask|(1<<n))|(1<<(n-1)) ) >> 1 ),x+1,y);
            dp[mask][x][y]%=1000000;
        }
        if (x-1>=0 && !(mask&(1<<n)) && !(mask&(1<<(n-1))) && x+1==n)
        {
            dp[mask][x][y]+=serc( ( ( (mask|(1<<n))|(1<<(n-1)) ) >> 1 ),0,y+1);
            dp[mask][x][y]%=1000000;
        }
    }
    dp[mask][x][y]%=1000000;
    return dp[mask][x][y];
}
int main()
{
    while (1<2)
    {
        scanf("%d%d",&n,&m);
        if (n==0&&m==0)break;
        for (int i=0;i<(1<<15);i++)
        {
            for (int j=0;j<n;j++)
            {
                for (int k=0;k<m;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        printf ("%d\n",serc(0,0,0));
    }
}

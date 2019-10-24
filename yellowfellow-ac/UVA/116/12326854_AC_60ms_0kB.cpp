//UVA 116 Unidirectional TSP
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
long long int dp[15][105][2];
long long int ar[15][105];
int n,m;
long long int serc(int h, int x)
{
    if (x==m)return 0;
    if (dp[h][x][0]!=-1)
    {
        return dp[h][x][0];
    }
    long long int rem=ar[h][x]+serc((h-1+n)%n,x+1);
    long long int ram=ar[h][x]+serc(h,x+1);
    long long int rom=ar[h][x]+serc((h+1)%n,x+1);
    dp[h][x][0]=ram;
    dp[h][x][1]=0;
    if (h==0)
    {
        if (rom<dp[h][x][0])
        {
            dp[h][x][0]=rom;
            dp[h][x][1]=1;
        }
        if (rem<dp[h][x][0])
        {
            dp[h][x][0]=rem;
            dp[h][x][1]=-1;
        }
    }
    else if (h==n-1)
    {
        if (rem<=dp[h][x][0])
        {
            dp[h][x][0]=rem;
            dp[h][x][1]=-1;
        }
        if (rom<=dp[h][x][0])
        {
            dp[h][x][0]=rom;
            dp[h][x][1]=1;
        }
    }
    else if (h>0)
    {
        if (rem<=dp[h][x][0])
        {
            dp[h][x][0]=rem;
            dp[h][x][1]=-1;
        }
        if (rom<dp[h][x][0])
        {
            dp[h][x][0]=rom;
            dp[h][x][1]=1;
        }
    }
    return dp[h][x][0];
}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                dp[i][j][0]=-1;
                scanf("%lld",&ar[i][j]);
            }
        }
        long long int res=((long long)1<<32);
        int pick;
        long long int tem;
        for (int i=0;i<n;i++)
        {
            tem=serc(i,0);
            if (tem<res)
            {
                pick=i;
                res=tem;
            }
        }
        int in=0;
        while (in<m)
        {
            printf ("%d",pick+1);
            pick+=dp[pick][in][1];
            pick+=n;
            pick%=n;
            in++;
            if (in<m)printf (" ");
        }
        printf ("\n%lld\n",res);
    }
}

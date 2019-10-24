//UVA 10520 Determine it
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
long long int dp[25][25];
int n;
long long int serc(int i,int j)
{
    long long int ret=0;
    long long int rat=0;
    if (dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if (i>=j)
    {
        ret=0;
        if (i<n)
        {
            for (int k=i+1;k<=n;k++)
            {
                ret=max(ret,serc(k,1)+serc(k,j));
            }
        }
        rat=0;
        if (j>0)
        {
            for (int k=1;k<j;k++)
            {
                rat=max(rat,serc(i,k)+serc(n,k));
            }
        }
        return dp[i][j]=ret+rat;
    }
    else
    {
        ret=0;
        for (int k=i;k<j;k++)
        {
            ret=max(ret,serc(i,k)+serc(k+1,j));
        }
        return dp[i][j]=ret;
    }
}
int main()
{
    int a;
    while (scanf("%d%d",&n,&a)!=EOF)
    {
        for (int i=0;i<25;i++)
        {
            for (int j=0;j<25;j++)
            {
                dp[i][j]=-1;
            }
        }
        dp[n][1]=a;
        serc(1,n);
        printf ("%lld\n",dp[1][n]);
    }
}

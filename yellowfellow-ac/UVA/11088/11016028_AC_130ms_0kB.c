#include <stdio.h>
int dp[1<<16];
int max(int a,int b)
{
    if (a>b)
        return a;
    return b;
}
int sear(int ppl[], int n, int mask)
{
    if (mask==(1<<n)-1)return 0;
    if (dp[mask]!=-1)
    {
        return dp[mask];
    }
    int maxi=0;
    int i,j,k;
    for (i=0;i<n;i++)
    {
        if ((mask&(1<<i))>0)continue;
        for (j=i+1;j<n;j++)
        {
            if ((mask&(1<<j))>0)continue;
            for (k=j+1;k<n;k++)
            {
                if ((mask&(1<<k))>0)continue;
                int m=mask;
                m|=1<<i;
                m|=1<<j;
                m|=1<<k;
                int d=ppl[i]+ppl[j]+ppl[k];
                if (d>=20)
                {
                    maxi=max(maxi,1+sear(ppl,n,m));
                }
            }
        }
    }
    return dp[mask]=maxi;
}
int main()
{
    int kasus=1;
    while (1<2)
    {
        int n;
        scanf("%d",&n);
        if (n==0)break;
        int i;
        int ppl[n];
        for (i=0;i<n;i++)
        {
            scanf("%d",&ppl[i]);
        }
        for (i=0;i<(1<<16);i++)
        {
            dp[i]=-1;
        }
        int x=sear(ppl,n,0);
        if (x<0)x=0;
        printf ("Case %d: %d\n",kasus,x);
        kasus++;
    }
    return 0;
}

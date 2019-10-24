//UVA 10934 Dropping water balloons
#include <stdio.h>
long long int dp[105][64];
long long int serc(int b,int k)
{
    if (b==0||k==0)return 0;
    if (dp[b][k]>0)return dp[b][k];
    return dp[b][k]=1+serc(b-1,k-1)+serc(b,k-1);
}
int main()
{
    for (int i=0;i<=100;i++)
    {
        serc(i,63);
    }
    while (1<2)
    {
        int n;
        long long int k;
        scanf("%d%lld",&n,&k);
        if (n==0)break;
        int i=0;
        for (;i<64;i++)
        {
            if (dp[n][i]>=k)
            {
                break;
            }
        }
        if (i>63)printf ("More than 63 trials needed.\n");
        else printf ("%d\n",i);
    }
}

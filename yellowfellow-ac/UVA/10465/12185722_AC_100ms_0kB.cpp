#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m,n,t;
    while (scanf("%d%d%d",&m,&n,&t)!=EOF)
    {
        int dp[t+1];
        for (int i=0;i<t+1;i++)
        {
            dp[i]=0;
        }
        dp[0]=1;
        for (int i=0;i<t+1;i++)
        {
            if (i-n>=0&&dp[i-n]>0)
            {
                dp[i]=max(dp[i],dp[i-n]+1);
            }
        }
        for (int i=0;i<t+1;i++)
        {
            if (i-m>=0&&dp[i-m]>0)
            {
                dp[i]=max(dp[i],dp[i-m]+1);
            }
        }
        if (dp[t]>0)
        {
            printf ("%d\n",dp[t]-1);
        }
        else
        {
            for (int i=t;i>=0;i--)
            {
                if (dp[i]>0)
                {
                    printf ("%d %d\n",dp[i]-1,t-i);
                    break;
                }
            }
        }
    }
}

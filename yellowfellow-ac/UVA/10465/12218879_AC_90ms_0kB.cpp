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
        dp[0]=1;
        int maxi=0;
        if (t%m==0&&t%n==0)
        {
        	maxi=t/m;
        	maxi=max(maxi,t/n);
		}
		if (maxi!=0)
		{
			printf ("%d\n",maxi);
			continue;
		}
        for (int i=0;i<t+1;i++)
        {
            if (i>0)dp[i]=0;
            if (i-n>=0&&dp[i-n]>0)
                dp[i]=max(dp[i],dp[i-n]+1);
            if (i-m>=0&&dp[i-m]>0)
                dp[i]=max(dp[i],dp[i-m]+1);
            if (dp[i]>0)maxi=i;
        }
        if (maxi==t)
            printf ("%d\n",dp[t]-1);
        else printf ("%d %d\n",dp[maxi]-1,t-maxi);
    }
}
//UVA 10943 How do you add?
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int dp[105][105];
int main()
{
    for (int i=0;i<105;i++)
    {
        dp[i][1]=1;
    }
    for (int i=2;i<105;i++)
    {
        for (int j=0;j<105;j++)
        {
            for (int k=0;k<=j;k++)
            {
                dp[j][i]+=dp[k][i-1];
                dp[j][i]%=1000000;
            }
        }
    }
    while (1<2)
    {
        int n,m;
        cin>>n>>m;
        if (n==0&&m==0)break;
        printf ("%d\n",dp[n][m]);
    }
}

//UVA 11003 Boxes
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int n;
int box[1001][2];
int dp[1001][6005];
int serc(int x, int w)
{
    if (x==n)return 0;
    if (dp[x][w]!=-1)return dp[x][w];
    dp[x][w]=0;
    if (w-box[x][0]>=0)
    {
        dp[x][w]=max(dp[x][w],1+serc(x+1,min(w-box[x][0],box[x][1])));
    }
    dp[x][w]=max(dp[x][w],serc(x+1,w));
    return dp[x][w];
}
int main()
{
    while (1<2)
    {
        cin>>n;
        if (n==0)break;
        for (int i=0;i<n;i++)
        {
            cin>>box[i][0];
            cin>>box[i][1];
            for (int j=0;j<6005;j++)
            {
                dp[i][j]=-1;
            }
        }
        printf ("%d\n",serc(0,6004));
    }
}

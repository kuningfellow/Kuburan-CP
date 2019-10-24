//UVA 1196 Tiling Up Blocks
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int ar[105][105];
int dp[105][105];
int lx,ly;
int serc(int l, int m)
{
    if (l>100||m>100)return 0;
    int ret=0;
    if (dp[l][m]!=-1)
    {
        return dp[l][m];
    }
    ret=max(ret,serc(l+1,m));
    ret=max(ret,serc(l,m+1));
    ret=max(ret,serc(l+1,m+1));
    return dp[l][m]=ret+ar[l][m];
}
int main()
{
    while (1<2)
    {
        for (int i=0;i<105;i++)
        {
            for (int j=0;j<105;j++)
            {
                dp[i][j]=-1;
                ar[i][j]=0;
            }
        }
        int n;
        cin>>n;
        if (n==0)break;
        int a,b;
        for (int i=0;i<n;i++)
        {
            cin>>a>>b;
            ar[a][b]++;
        }
        printf ("%d\n",serc(0,0));
    }
    printf ("*\n");
}

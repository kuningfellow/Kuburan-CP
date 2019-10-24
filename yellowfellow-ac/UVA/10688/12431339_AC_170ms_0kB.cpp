//UVA 10688 The Poor Giant
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int dp[505][250005];
int serc(int n, int k)
{
    if (n==0||n==1)return 0;
    if (dp[n][k]>0)
    {
        return dp[n][k];
    }
    int ret=(1<<30);
    for (int i=1;i<=n;i++)
    {
        ret=min(ret,(k+i)*n+serc(n-i,k+i)+serc(i-1,k));
    }
    return dp[n][k]=ret;
}
int main()
{
    int tc,kas=1;
    cin>>tc;
    while (tc--)
    {
        int a,b;
        cin>>a>>b;
        printf ("Case %d: %d\n",kas++,serc(a,b));
    }
}

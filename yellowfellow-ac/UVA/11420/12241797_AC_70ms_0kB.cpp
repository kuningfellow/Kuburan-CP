//UVA 11420 Chest of Drawers
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
long long int dp[67][67][2];
long long int rem[67][67];
int ca;
long long int serc(int x, int s,int p)
{
    if (x==0)
    {
        if (s==ca)return 1;
        else return 0;
    }
    if (dp[x][s][p]!=-1)
    {
        return dp[x][s][p];
    }
    long long int ret=0;
    if (p==1)
    {
        ret+=serc(x-1,s+1,1);
    }
    else
    {
        ret+=serc(x-1,s,1);
    }
    ret+=serc(x-1,s,0);
    return dp[x][s][p]=ret;
}
int main()
{
    for (ca=0;ca<67;ca++)
    for (int i=0;i<67;i++)
    {
        for (int j=0;j<67;j++)
        {
            for (int k=0;k<67;k++)
            {
                dp[j][k][0]=-1;
                dp[j][k][1]=-1;
            }
        }
        rem[i][ca]=serc(i,0,1);
    }
    while (1<2)
    {
        int n,es;
        cin>>n>>es;
        if (n<0&&es<0)break;
        printf ("%lld\n",rem[n][es]);
    }
}

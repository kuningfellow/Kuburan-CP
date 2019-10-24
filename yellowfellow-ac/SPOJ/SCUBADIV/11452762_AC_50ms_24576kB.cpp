#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int tank[1005][3];
int q;
int o,n;
int dp[1005][25][90];
int serc(int x, int ox, int ni)
{
    if (ox>=o&&ni>=n)return 0;
    if (x==q)
    {
        if (ox>=o&&ni>=n)return 0;
        else return 1000000000;
    }
    if (dp[x][ox][ni]>0)
    {
        return dp[x][ox][ni];
    }
    int a;
        a=ox+tank[x][0];
    int b;
        b=ni+tank[x][1];
    dp[x][ox][ni]=min(tank[x][2]+serc(x+1,min(a,o),min(b,n)),serc(x+1,ox,ni));
    return dp[x][ox][ni];
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&o,&n);
        scanf("%d",&q);
        for (int i=0;i<q;i++)
        {
            scanf("%d%d%d",&tank[i][0],&tank[i][1],&tank[i][2]);
        }
        for (int i=0;i<q;i++)
        {
            for (int j=0;j<25;j++)
            {
                for (int k=0;k<90;k++)
                {
                    dp[i][j][k]=0;
                }
            }
        }
        cout<<serc(0,0,0)<<endl;
    }
}

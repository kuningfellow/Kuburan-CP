//UVA 11137 Ingenuous Cubrency
#include <stdio.h>
#include <vector>
using namespace std;
const int coins[21]={1*1*1,2*2*2,3*3*3,4*4*4,5*5*5,6*6*6,7*7*7,8*8*8,9*9*9,10*10*10,11*11*11,12*12*12,13*13*13,14*14*14,15*15*15,16*16*16,17*17*17,18*18*18,19*19*19,20*20*20,21*21*21};
int target;
long long int dp[10001][21];
long long int fin(int monet, int con)
{
    if (monet==target)return 1;
    if (dp[monet][con]!=-1)return dp[monet][con];
    dp[monet][con]=0;
    for (int i=0;i<=con;i++)
    {
        if (monet+coins[i]<=target)
        {
            dp[monet][con]+=fin(monet+coins[i],i);
        }
    }
    return dp[monet][con];
}
long long int stor[10001];
int main()
{
    while (scanf("%d",&target)!=EOF)
    {
        if (stor[target]==0)
        {
            for (int i=0;i<=target;i++)
            {
                for (int j=0;j<21;j++)
                    dp[i][j]=-1;
            }
            stor[target]=fin(0,20);
        }
        printf ("%lld\n",stor[target]);
    }
}

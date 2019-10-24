#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int dp[27][27][352];
int l;
int s;
int serc(int x, int a, int v)
{
    if (x==l)
    {
        if (v==s)return 1;
        else return 0;
    }
    if (a>=26)return 0;
    if (dp[x][a][v]!=-1)
    {
        return dp[x][a][v];
    }
    int ret=0;
    for (int i=a;i<26;i++)
    {
        ret+=serc(x+1,i+1,v+1+i);
    }
    return dp[x][a][v]=ret;
}
int main()
{
    int kas=1;
    while (1<2)
    {
        cin>>l>>s;
        if (l==0&&s==0)break;
        if (l>26||s>351)
        {
            printf ("Case %d: 0\n",kas++);
            continue;
        }
        for (int i=0;i<27;i++)
        {
            for (int j=0;j<27;j++)
            {
                for (int k=0;k<352;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        printf ("Case %d: %d\n",kas++,serc(0,0,0));
    }
}

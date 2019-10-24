#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int n;
int p;
vector<int>pplcarry;
vector<int>shit[2];
int dp[1001][31][31];
int serc(int x, int w, int ppl)
{
    if (x==n)return 0;
    if (dp[x][w][ppl]>0)return dp[x][w][ppl];
    dp[x][w][ppl]=0;
    if (shit[1][x]+w<=ppl)
    {
        dp[x][w][ppl]+=shit[0][x]+serc(x+1,w+shit[1][x],ppl);
    }
    dp[x][w][ppl]=max(dp[x][w][ppl],serc(x+1,w,ppl));
    return dp[x][w][ppl];
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<31;j++)
            {
                for (int k=0;k<31;k++)
                {
                    dp[i][j][k]=0;
                }
            }
        }
        for (int i=0;i<n;i++)
        {
            cin>>a>>b;
            shit[0].push_back(a);
            shit[1].push_back(b);
        }
        cin>>p;
        for (int i=0;i<p;i++)
        {
            cin>>a;
            pplcarry.push_back(a);
        }
        int val=0;
        for (int i=0;i<p;i++)
        {
            val+=serc(0,0,pplcarry[i]);
        }
        printf ("%d\n",val);
        pplcarry.clear();
        shit[0].clear();
        shit[1].clear();
    }
}

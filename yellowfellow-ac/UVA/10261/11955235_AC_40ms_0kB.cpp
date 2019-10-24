//UVA 10261 Ferry Loading
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int dp[205][10000][2];
vector<int>cars;
vector<int>sumcar;
int L;
int serc(int x, int l)
{
    if (dp[x][l][0]>0)return dp[x][l][0];
    if (x>=cars.size())return 0;
    int rig=0;
    int lef=0;
    if (sumcar[x]+cars[x]-l<=L)
    {
        rig=1+serc(x+1,l);
    }
    if (l+cars[x]<=L)
    {
        lef=1+serc(x+1,l+cars[x]);
    }
    if (lef<rig)
    {
        dp[x][l][0]=rig;
        dp[x][l][1]=l;
    }
    else
    {
        dp[x][l][0]=lef;
        dp[x][l][1]=l+cars[x];
    }
    return dp[x][l][0];
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        cin>>L;
        L*=100;
        int a;
        cars.clear();
        sumcar.clear();
        while (1<2)
        {
            cin>>a;
            if (a==0)break;
            cars.push_back(a);
        }
        int sum=0;
        for (int i=0;i<cars.size();i++)
        {
            sumcar.push_back(sum);
            sum+=cars[i];
        }
        int ans=serc(0,0);
        printf ("%d\n",ans);
        int b=0;
        a=0;
        for (int i=0;i<ans;i++)
        {
            if (b==dp[a][b][1])
            {
                printf ("starboard\n");
            }
            else
            {
                printf ("port\n");
            }
            b=dp[a][b][1];
            a++;
        }
        if (tc>0)
        {
            printf ("\n");
            for (int i=0;i<205;i++)
            {
                for (int j=0;j<10000;j++)
                {
                    dp[i][j][0]=0;
                }
            }
        }
    }
}

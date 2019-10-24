#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int n,q;
vector<int>num;
vector<int>qer[2];
int dp[201][21][11][11][21];
int serc(int x, int q, int picked, int sum)
{
    if (picked==qer[1][q]&&sum%qer[0][q]==0)
    {
        return 1;
    }
    else if (x==n)
    {
        return 0;
    }
    if (dp[x][qer[0][q]][qer[1][q]][picked][sum]>0)return dp[x][qer[0][q]][qer[1][q]][picked][sum];
    if (picked+1<=qer[1][q])
    {
        int temp=sum+num[x];
        while (temp<0)
        {
            temp+=qer[0][q];
        }
        dp[x][qer[0][q]][qer[1][q]][picked][sum]+=serc(x+1,q,picked+1,temp%qer[0][q]);
    }
    dp[x][qer[0][q]][qer[1][q]][picked][sum]+=serc(x+1,q,picked,sum);
    return dp[x][qer[0][q]][qer[1][q]][picked][sum];
}
int main()
{
    int co=1;
    while (1<2)
    {
        cin>>n>>q;
        for (int i=0;i<n;i++)
            for (int j=0;j<21;j++)
                for (int k=0;k<11;k++)
                    for (int l=0;l<11;l++)
                        for (int m=0;m<21;m++)
                            dp[i][j][k][l][m]=0;
        int a,b;
        if (n==0&&q==0)break;
        for (int i=0;i<n;i++)
        {
            cin>>a;
            num.push_back(a);
        }
        printf ("SET %d:\n",co);
        co++;
        for (int j=0;j<q;j++)
        {
            cin>>a>>b;
            qer[0].push_back(a);
            qer[1].push_back(b);
            printf ("QUERY %d: %d\n",j+1,serc(0,j,0,0));
        }
        num.clear();
        qer[0].clear();
        qer[1].clear();
    }
}

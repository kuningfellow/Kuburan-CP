//UVA 10400 Game Show Math
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int dp[105][64010][2];
int num[105];
int p;
int tar;
int serc(int n, int rem)
{
    if (rem<-32000||rem>32000)
    {
        return 0;
    }
    if (n==p&&rem==tar)
    {
        return 1;
    }
    if (n==p)return 0;
    if (dp[n][rem+32000][0]!=-1)
    {
        return dp[n][rem+32000][0];
    }
    int res[4]={0,0,0,0};
    res[0]=serc(n+1,rem+num[n]);
    if (res[0]==1)
    {
        dp[n][rem+32000][1]=1;
        dp[n][rem+32000][0]=1;
        return dp[n][rem+32000][0];
    }
    res[1]=serc(n+1,rem-num[n]);
    if (res[1]==1)
    {
        dp[n][rem+32000][1]=2;
        dp[n][rem+32000][0]=1;
        return dp[n][rem+32000][0];
    }
    res[2]=serc(n+1,rem*num[n]);
    if (res[2]==1)
    {
        dp[n][rem+32000][1]=3;
        dp[n][rem+32000][0]=1;
        return dp[n][rem+32000][0];
    }
    res[3]=0;
    if (num[n]!=0)
    {
        res[3]=serc(n+1,rem/num[n]);
    }
    if (res[3]==1)
    {
        dp[n][rem+32000][1]=4;
        dp[n][rem+32000][0]=1;
        return dp[n][rem+32000][0];
    }
    return dp[n][rem+32000][0]=0;
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        cin>>p;
        for (int i=0;i<=p;i++)
        {
            for (int j=0;j<64010;j++)
            {
                dp[i][j][0]=-1;
            }
        }
        for (int i=0;i<p;i++)
        {
            cin>>num[i];
        }
        cin>>tar;
        int re=serc(1,num[0]);
        if (re==0)
        {
            printf ("NO EXPRESSION\n");
        }
        else
        {
            int x=0;
            int rem=num[x];
            int op;
            while (1<2)
            {
                printf ("%d",num[x]);
                x++;
                if (x==p)
                {
                    printf ("=%d\n",tar);
                    break;
                }
                op=dp[x][rem+32000][1];
                if (op==1)
                {
                    printf ("+");
                    rem=rem+num[x];
                }
                if (op==2)
                {
                    printf ("-");
                    rem=rem-num[x];
                }
                if (op==3)
                {
                    printf ("*");
                    rem=rem*num[x];
                }
                if (op==4)
                {
                    printf ("/");
                    rem=rem/num[x];
                }
            }
        }
    }
}

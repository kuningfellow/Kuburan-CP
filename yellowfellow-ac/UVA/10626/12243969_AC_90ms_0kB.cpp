//UVA 10626 Buying Coke
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int dp[155][505][101][55];
int serc(int co, int a, int b, int c)
{
    if (co==0)return 0;
    int rem=100000;
    int one=0,two=0,three=0;
    if (dp[co][a][b][c]>0)
    {
        return dp[co][a][b][c];
    }
    if (c>0&&a>2)
    {
        rem=min(rem,4+serc(co-1,a-3,b+1,c-1));
        if (rem!=100000)
        {
            one=1;
        }
    }
    if (c>0)
    {
        rem=min(rem,1+serc(co-1,a+2,b,c-1));
        if (rem!=100000)
        {
            one=1;
        }
    }
    if (one==0&&b>1)
    {
        rem=min(rem,2+serc(co-1,a+2,b-2,c));
        if (rem!=100000)
        {
            two=1;
        }
    }
    if (one==0&&b>0&&a>2)
    {
        rem=min(rem,4+serc(co-1,a-3,b-1,c));
        if (rem!=100000)
        {
            two=1;
        }
    }
    if (one==0&&two==0&&a>7)
    {
        rem=min(rem,8+serc(co-1,a-8,b,c));
    }
    return dp[co][a][b][c]=rem;
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int a,b,c,co;
        cin>>co>>a>>b>>c;
        printf ("%d\n",serc(co,a,b,c));
    }
}

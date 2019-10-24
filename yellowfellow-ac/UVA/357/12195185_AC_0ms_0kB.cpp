//UVA 357 Let Me Count The Ways
//top down more efficient
#include <stdio.h>
#include <iostream>
using namespace std;
int co[5]={1,5,10,25,50};
long long int dp[30005][5];
long long int serc (int m, int c)
{
    if (m==0)
    {
        return 1;
    }
    else if (m<0)
    {
        return 0;
    }
    for (int i=0;i<=c;i++)
    {
        if (dp[m][c]!=-1)
        {
            return dp[m][c];
        }
    }
    dp[m][0]=0;
    for (int i=0;i<5;i++)
    {
        if (i>0)
        {
            dp[m][i]=dp[m][i-1];
        }
        dp[m][i]+=serc(m-co[i],i);
    }
    return dp[m][c];
}
int main()
{
    int n=30000;
    long long int way;
    for (int i=0;i<n+1;i++)
    {
        for (int j=0;j<5;j++)
        {
            dp[i][j]=-1;
        }
    }
    dp[0][4]=1;
    serc(n,4);
    while (scanf("%d",&n)!=EOF)
    {
        way=dp[n][4];
        if (way==1)
            printf ("There is only 1 way to produce %d cents change.\n",n);
        else
            printf ("There are %lld ways to produce %d cents change.\n",way,n);
    }
}

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int n;
int ar[31][3];
int dp[50000];
int serc(int a, int b, int h)
{
    if (dp[h]>0)
    {
        return dp[h];
    }
    int maxi=0;
    int stop=0;
    for (int i=0;i<n;i++)
    {
        if (ar[i][0]<a&&ar[i][1]<b)
        {
            maxi=max(maxi,ar[i][2]+serc(ar[i][0],ar[i][1],ar[i][2]));
        }
        if (ar[i][0]<b&&ar[i][1]<a)
        {
            maxi=max(maxi,ar[i][2]+serc(ar[i][1],ar[i][0],ar[i][2]));
        }
        if (ar[i][0]<a&&ar[i][2]<b)
        {
            maxi=max(maxi,ar[i][1]+serc(ar[i][0],ar[i][2],ar[i][1]));
        }
        if (ar[i][2]<a&&ar[i][0]<b)
        {
            maxi=max(maxi,ar[i][1]+serc(ar[i][2],ar[i][0],ar[i][1]));
        }
        if (ar[i][1]<a&&ar[i][2]<b)
        {
            maxi=max(maxi,ar[i][0]+serc(ar[i][1],ar[i][2],ar[i][0]));
        }
        if (ar[i][2]<a&&ar[i][1]<b)
        {
            maxi=max(maxi,ar[i][0]+serc(ar[i][2],ar[i][1],ar[i][0]));
        }
    }
    dp[h]=maxi;
    return maxi;
}
int main()
{
    int kas=1;
    while (1<2)
    {
        cin>>n;
        if (n==0)break;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d%d",&ar[i][0],&ar[i][1],&ar[i][2]);
        }
        for (int i=0;i<50000;i++)
        {
            dp[i]=0;
        }
        printf ("Case %d: maximum height = %d\n",kas++,serc((1<<30),(1<<30),0));
    }
}

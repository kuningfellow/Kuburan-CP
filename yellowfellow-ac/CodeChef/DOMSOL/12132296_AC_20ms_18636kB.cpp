#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dif(int a, int b)
{
    if (a>b)return a-b;
    else return b-a;
}
int ar[100005][2];
int dp[100005];
int n;
int serc(int x)
{
    if (x>n+1)return -1000000000;
    if (x==n)return 0;
    if (dp[x]>0)return dp[x];
    int temp=0;
    dp[x]=max(dif(ar[x][0],ar[x][1])+serc(x+1),dif(ar[x][0],ar[x+1][0])+dif(ar[x][1],ar[x+1][1])+serc(x+2));
    return dp[x];
}
int main()
{
    cin>>n;
    for (int j=0;j<2;j++)
    for (int i=0;i<n;i++)
    {
        scanf("%d",&ar[i][j]);
    }
    printf ("%d\n",serc(0));
}

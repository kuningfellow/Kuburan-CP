//UVA 562 Dividing coins
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int abs(int a, int b)
{
    if (a>b)return a-b;
    else return b-a;
}
int best[50000][505];
int coin[10000];
int n;
int fin(int bag1,int bag2,int k)
{
    if (k==n)
    {
        return abs(bag1,bag2);
    }
    if (k<n)
    {
        if (best[bag1][k]!=-1)
        {
            return best[bag1][k];
        }
    }
    int i,j;
    j=min( fin(bag1+coin[k],bag2,k+1 ),fin(bag1,bag2+coin[k],k+1));
    best[bag1][k+1]=min(j,best[bag1][k+1]);
    if (best[bag1][k+1]==-1)best[bag1][k+1]=j;
    return best[bag1][k+1];
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        int i,j;
        for(i=0;i<50000;i++)
        {
            for (j=0;j<505;j++)
                best[i][j]=-1;
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&coin[i]);
        }
        cout<<fin(0,0,0)<<endl;
    }
}

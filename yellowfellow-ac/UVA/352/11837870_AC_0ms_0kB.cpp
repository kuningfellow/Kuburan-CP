//UVA 352 The Seasonal War
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
char ma[27][27];
int n;
int dfs(int x, int y)
{
    if (ma[x][y]!='0')
        ma[x][y]='0';
    else return 0;
    if (x+1<n)dfs(x+1,y);
    if (x+1<n&&y+1<n)dfs(x+1,y+1);
    if (y+1<n)dfs(x,y+1);
    if (x-1>=0&&y+1<n)dfs(x-1,y+1);
    if (x-1>=0)dfs(x-1,y);
    if (x-1>=0&&y-1>=0)dfs(x-1,y-1);
    if (y-1>=0)dfs(x,y-1);
    if (x+1<n&&y-1>=0)dfs(x+1,y-1);
}
int main()
{
    int kase=1;
    while (1<2)
    {
        if (scanf("%d",&n)==EOF)break;
        for (int i=0;i<n;i++)
        {
            scanf("%s",ma[i]);
        }
        int co=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (ma[i][j]!='0')
                {
                    co++;
                    dfs(i,j);
                }
            }
        }
        printf ("Image number %d contains %d war eagles.\n",kase++,co);
    }
}

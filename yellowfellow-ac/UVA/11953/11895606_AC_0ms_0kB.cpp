//UVA 11953 Battleships
#include <stdio.h>
#include <iostream>
using namespace std;
char ar[101][101];
int n;
void dfs(int x, int y)
{
    if (ar[x][y]!='.')
    {
        ar[x][y]='.';
        if (x-1>=0)dfs(x-1,y);
        if (x+1<n)dfs(x+1,y);
        if (y-1>=0)dfs(x,y-1);
        if (y+1<n)dfs(x,y+1);
    }
}
int main()
{
    int tc;
    cin>>tc;
    int kas=1;
    while (tc--)
    {
        cin>>n;
        for (int i=0;i<n;i++)
        {
            scanf("%s",ar[i]);
        }
        int co=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (ar[i][j]=='x')
                {
                    co++;
                    dfs(i,j);
                }
            }
        }
        printf ("Case %d: %d\n",kas++,co);
    }
}

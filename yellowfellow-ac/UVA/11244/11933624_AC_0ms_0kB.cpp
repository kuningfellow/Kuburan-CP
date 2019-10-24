//UVA 11094 Continents
#include <stdio.h>
#include <iostream>
using namespace std;
char ar[101][101];
int n,m;
int dfs(int x, int y)
{
    int temp;
    if (ar[x][y]!='*')return 0;
    else if (ar[x][y]=='*')
    {
        temp=1;
        ar[x][y]='.';
        if (x+1<n)temp+=dfs(x+1,y);
        if (y+1<m)temp+=dfs(x,y+1);
        if (x-1>=0)temp+=dfs(x-1,y);
        if (y-1>=0)temp+=dfs(x,y-1);
        if (x+1<n&&y+1<m)temp+=dfs(x+1,y+1);
        if (x+1<n&&y-1>=0)temp+=dfs(x+1,y-1);
        if (x-1>=0&&y+1<m)temp+=dfs(x-1,y+1);
        if (x-1>=0&&y-1>=0)temp+=dfs(x-1,y-1);
    }
    return temp;
}
int main()
{
    while (1<2)
    {
        scanf("%d%d",&n,&m);
        if (n==0&&m==0)break;
        for (int i=0;i<n;i++)
                scanf("%s",ar[i]);
        int maxi=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (ar[i][j]=='*')
                {
                    if (dfs(i,j)==1)
                        maxi++;
                }
            }
        }
        printf ("%d\n",maxi);
    }
}

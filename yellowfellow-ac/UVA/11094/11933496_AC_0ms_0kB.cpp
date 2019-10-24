//UVA 11094 Continents
#include <stdio.h>
#include <iostream>
using namespace std;
char ar[21][21];
int X,Y;
int n,m;
char l;
int dfs(int x, int y)
{
    if (x==X&&y==Y)return -(1<<28);
    int temp;
    if (ar[x][y]!=l)return 0;
    else
    {
        ar[x][y]=l+1;
        temp=1;
    }
    if (x+1<n)temp+=dfs(x+1,y);
    if (x-1>=0)temp+=dfs(x-1,y);
    temp+=dfs(x,(y+1+m)%m);
    temp+=dfs(x,(y-1+m)%m);
    return temp;
}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<n;i++)
                scanf("%s",ar[i]);
        scanf("%d%d",&X,&Y);
        int maxi=0;
        int tamp;
        l=ar[X][Y];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (ar[i][j]==l)
                {
                    tamp=dfs(i,j);
                    if (tamp>maxi)maxi=tamp;
                }
            }
        }
        printf ("%d\n",maxi);
    }
}

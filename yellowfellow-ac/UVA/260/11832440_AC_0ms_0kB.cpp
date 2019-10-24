//UVA 260 Gioco dell'X
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
char ma[201][201];
int n;
int l,r;
int dfs(int x, int y)
{
    if (ma[x][y]=='w')
    {
        ma[x][y]='c';
        if (y==0)
            l=1;
        if (y==n-1)
            r=1;
    }
    else return 0;
    if (y+1<n&&ma[x][y+1]!='c')dfs(x,y+1);
    if (y-1>=0&&ma[x][y-1]!='c')dfs(x,y-1);
    if (x+1<n&&y+1<n&&ma[x+1][y+1]!='c')dfs(x+1,y+1);
    if (x-1>=0&&y-1>=0&&ma[x-1][y-1]!='c')dfs(x-1,y-1);
    if (x+1<n&&ma[x+1][y]!='c')dfs(x+1,y);
    if (x-1>=0&&ma[x-1][y]!='c')dfs(x-1,y);
}

int main()
{
	int kas=1;
	while (1<2)
	{
		cin>>n;
		if (n==0)break;
		char ar[n+1];
		for (int i=0;i<n;i++)
		{
			scanf("%s",ar);
			for (int j=0;j<n;j++)
			{
				ma[i][j]=ar[j];
			}
		}
		int win=0;
		for (int i=0;i<n;i++)
		{
		    l=0;
            r=0;
            if (ma[i][0]=='w')
            {
                dfs(i,0);
            }
            if (l==1&&r==1)
            {
                win=1;
                printf ("%d W\n",kas++);
                break;
            }
		}
		if (win==1)continue;
        else printf ("%d B\n",kas++);
	}
}

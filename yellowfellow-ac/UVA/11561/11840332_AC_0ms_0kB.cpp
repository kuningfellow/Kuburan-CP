//UVA 11561 Getting Gold
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
char ma[52][52];
int n,m;
int co=0;
int dfs(int x, int y)
{
	if (ma[x][y]=='G')
	{
		co++;
	}
	ma[x][y]='#';
	int no=0;
	if (x+1<n&&ma[x+1][y]=='T')no=1;
	if (x-1>=0&&ma[x-1][y]=='T')no=1;
	if (y+1<m&&ma[x][y+1]=='T')no=1;
	if (y-1>=0&&ma[x][y-1]=='T')no=1;
	if (no==0)
	{
		if (x+1<n&&ma[x+1][y]!='#') dfs(x+1,y);
		if (x-1>=0&&ma[x-1][y]!='#')dfs(x-1,y);
		if (y+1<m&&ma[x][y+1]!='#')dfs(x,y+1);
		if (y-1>=0&&ma[x][y-1]!='#')dfs(x,y-1);
	}
}
int main()
{
	while (1<2)
	{
		if (scanf("%d%d",&m,&n)==EOF)break;
		co=0;
		for (int i=0;i<n;i++)
		{
			scanf("%s",ma[i]);
		}
		int x0,y0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (ma[i][j]=='P')
				{
					x0=i;
					y0=j;
				}
			}
		}
		dfs(x0,y0);
		printf ("%d\n",co);
	}
}
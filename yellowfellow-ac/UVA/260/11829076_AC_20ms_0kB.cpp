//UVA 260 Gioco dell'X
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
char ma[201][201];
int marw[201];
int marb[201];
int n;
int dfs(int x, int y, int m)
{
	int stop=0;
	if (m==0)
	{
		if (ma[x][y]=='w')
		{
			ma[x][y]='c';
			marw[y]=1;
		}
		else stop=1;
	}
	else if (m==1)
	{
		if (ma[x][y]=='b')
		{
			ma[x][y]='c';
			marb[x]=1;
		}
		else stop=1;
	}
	if (stop==0)
	{
		if (y+1<n&&ma[x][y+1]!='c')dfs(x,y+1,m);
		if (y-1>=0&&ma[x][y-1]!='c')dfs(x,y-1,m);
		if (x+1<n&&y+1<n&&ma[x+1][y+1]!='c')dfs(x+1,y+1,m);
		if (x-1>=0&&y-1>=0&&ma[x-1][y-1]!='c')dfs(x-1,y-1,m);
		if (x+1<n&&ma[x+1][y]!='c')dfs(x+1,y,m);
		if (x-1>=0&&ma[x-1][y]!='c')dfs(x-1,y,m);
	}
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
			if (ma[i][0]=='w')
			{
				dfs(i,0,0);
				int wh=1;
				for (int k=0;k<n;k++)
				{
					if (marw[k]!=1)
					{
						wh=0;
					}
					marw[k]=0;
				}
				if (wh==1)win=1;
			}
			else if (ma[i][0]=='b')
			{
				dfs(i,0,1);
				int wh=1;
				for (int k=0;k<n;k++)
				{
					if (marb[k]!=1)
					{
						wh=0;
					}
					marb[k]=0;
				}
				if (wh==1)win=2;
			}
		}
		if (win==1)printf ("%d W\n",kas++);
		else printf ("%d B\n",kas++);
	}
}
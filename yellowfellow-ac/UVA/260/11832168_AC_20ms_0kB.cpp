//UVA 260 Gioco dell'X
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
char ma[201][201];
int n;
int l,r,a,d;
int dfs(int x, int y, int m)
{
	if (m==0)
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
	}
	else if (m==1)
	{
		if (ma[x][y]=='b')
		{
			ma[x][y]='c';
			if (x==0)
                a=1;
            if (x==n-1)
                d=0;
		}
		else return 0;
	}
    if (y+1<n&&ma[x][y+1]!='c')dfs(x,y+1,m);
    if (y-1>=0&&ma[x][y-1]!='c')dfs(x,y-1,m);
    if (x+1<n&&y+1<n&&ma[x+1][y+1]!='c')dfs(x+1,y+1,m);
    if (x-1>=0&&y-1>=0&&ma[x-1][y-1]!='c')dfs(x-1,y-1,m);
    if (x+1<n&&ma[x+1][y]!='c')dfs(x+1,y,m);
    if (x-1>=0&&ma[x-1][y]!='c')dfs(x-1,y,m);
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
		    for (int j=0;j<n;j++)
            {
                l=0;
                r=0;
                a=0;
                d=0;
                if (ma[i][j]=='w')
                {
                    dfs(i,j,0);
                }
                else if (ma[i][j]=='b')
                {
                    dfs(i,j,1);
                }
                if (l==1&&r==1)win=1;
                else if (a==1&&d==1)win=2;
                if (win!=0)break;
            }
            if (win!=0)break;
		}
		if (win==1)printf ("%d W\n",kas++);
		else printf ("%d B\n",kas++);
	}
}

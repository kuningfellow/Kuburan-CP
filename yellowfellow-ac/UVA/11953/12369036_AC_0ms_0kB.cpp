#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int n;
char ma[105][105];
int visit[105][105];
void fil(int x, int y)
{
	visit[x][y]=1;
	ma[x][y]='@';
	if (x-1>=0&&ma[x-1][y]!='.'&&visit[x-1][y]==0)
	{
		fil(x-1,y);
	}
	if (x+1<n&&ma[x+1][y]!='.'&&visit[x+1][y]==0)
	{
		fil(x+1,y);
	}
	if (y-1>=0&&ma[x][y-1]!='.'&&visit[x][y-1]==0)
	{
		fil(x,y-1);
	}
	if (y+1<n&&ma[x][y+1]!='.'&&visit[x][y+1]==0)
	{
		fil(x,y+1);
	}
}
int main()
{
	int tc,kas=1;
	cin>>tc;
	while (tc--)
	{
		cin>>n;
		for (int i=0;i<n;i++)
		{
			scanf("%s",ma[i]);
		}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				visit[i][j]=0;
			}
		}
		int ship=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (ma[i][j]=='x')
				{
					ship++;
					fil(i,j);
				}
			}
		}
		printf ("Case %d: %d\n",kas++,ship);
	}
}		
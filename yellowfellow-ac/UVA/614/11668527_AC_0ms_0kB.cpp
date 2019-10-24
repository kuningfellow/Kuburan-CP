#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int maze[12][12][3];
int resmaze[12][12];
int wall[12][12];
int X,Y;
int x1,y1;
int ok=0;
int serc(int x,int y, int cost)
{
	if (y-1>=0&&maze[x][y-1][0]==0&&(wall[x][y-1]&1)==0&&ok==0)
	{
		maze[x][y-1][0]=cost;
		maze[x][y-1][1]=x;
		maze[x][y-1][2]=y;
		if (x==x1-1&&y-1==y1-1)
			ok=1;
		serc(x,y-1,cost+1);
	}
	if (x-1>=0&&maze[x-1][y][0]==0&&(wall[x-1][y]&2)==0&&ok==0)
	{
		maze[x-1][y][0]=cost;
		maze[x-1][y][1]=x;
		maze[x-1][y][2]=y;
		if (x-1==x1-1&&y==y1-1)
			ok=1;
		serc(x-1,y,cost+1);
	}
	if (y+1<Y&&maze[x][y+1][0]==0&&(wall[x][y]&1)==0&&ok==0)
	{
		maze[x][y+1][0]=cost;
		maze[x][y+1][1]=x;
		maze[x][y+1][2]=y;
		if (x==x1-1&&y+1==y1-1)
			ok=1;
		serc(x,y+1,cost+1);
	}
	if (x+1<X&&maze[x+1][y][0]==0&&(wall[x][y]&2)==0&&ok==0)
	{
		maze[x+1][y][0]=cost;
		maze[x+1][y][1]=x;
		maze[x+1][y][2]=y;
		if (x+1==x1-1&&y==y1-1)
			ok=1;
		serc(x+1,y,cost+1);
	}
}
int main()
{
	int kasus=1;
	int x0,y0;
	while (1<2)
	{
		scanf("%d%d%d%d%d%d",&X,&Y,&x0,&y0,&x1,&y1);
		if (X+Y==0)break;
		ok=0;
		for (int i=0;i<X;i++)
		{
			for (int j=0;j<Y;j++)
			{
				maze[i][j][0]=0;
				resmaze[i][j]=0;
			}
		}
		for (int i=0;i<X;i++)
		{
			for (int j=0;j<Y;j++)
			{
				scanf("%d",&wall[i][j]);
			}
		}
		int cost=2;
		int x,y;
		maze[x0-1][y0-1][0]=1;
		maze[x0-1][y0-1][1]=-1;
		maze[x0-1][y0-1][2]=-1;
		serc(x0-1,y0-1,2);
		x=x1-1;
		y=y1-1;
		while (x!=-1&&y!=-1)
		{
			resmaze[x][y]=maze[x][y][0];
			int temp=x;
			x=maze[temp][y][1];
			y=maze[temp][y][2];
		}
		printf ("Maze %d\n\n",kasus);
		kasus++;
		for (int i=0;i<Y*4+1;i++)
		{
			if (i%4==0)
				printf ("+");
			else printf ("-");
		}
		printf ("\n");
		for (int j=0;j<X*2-1;j++)
		{
			if ((j+1)%2==0)
			{
				for (int i=0;i<Y*4+1;i++)
				{
					if (i%4==0)
					{
						printf ("+");
					}
					else if ((wall[j/2][i/4]&2))
					{
						printf ("-");
					}
					else printf (" ");
				}
			}
			else
			{
				for (int i=0;i<Y*4+1;i++)
				{
					if (i==0||i==Y*4)printf ("|");
					else if (i%4==0)
					{
						if ((wall[j/2][(i-1)/4]&1))
							printf ("|");
						else printf (" ");
					}
					else
					{
						if (maze[j/2][i/4][0]==0)printf ("   ");
						else if (resmaze[j/2][i/4]!=0)printf ("%3d",resmaze[j/2][i/4]);
						else if (resmaze[j/2][i/4]==0)printf ("???");
						i+=2;
					}
				}
			}
			printf ("\n");
		}
		for (int i=0;i<Y*4+1;i++)
		{
			if (i%4==0)
				printf ("+");
			else printf ("-");
		}
		printf ("\n\n\n");
	}
}
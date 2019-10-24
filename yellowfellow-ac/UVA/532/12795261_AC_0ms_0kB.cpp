//UVA 532 Dungeon Master
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    while (1<2)
    {
        int n,m,o;
        cin>>n>>m>>o;
        if (n==0&&m==0&&o==0)break;
        char rem[n][m][o+1];
        int vis[n][m][o];
        int x1,y1,z1,x2,y2,z2,x,y,z;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                scanf("%s",rem[i][j]);
                for (int k=0;k<o;k++)
                {
                    vis[i][j][k]=0;
                    if (rem[i][j][k]=='S')
                    {
                        x1=i;
                        y1=j;
                        z1=k;
                    }
                    if (rem[i][j][k]=='E')
                    {
                        x2=i;
                        y2=j;
                        z2=k;
                    }
                }
            }
        }
        queue<pair<int,pair<int,int> > >q;
        q.push(pair<int,pair<int,int> >(x1,pair<int,int>(y1,z1)));
        int siz,step=1;
        while (!q.empty())
        {
            siz=q.size();
            for (int i=0;i<siz;i++)
            {
                x=q.front().first;
                y=q.front().second.first;
                z=q.front().second.second;
                if (x+1<n&&rem[x+1][y][z]!='#'&&vis[x+1][y][z]==0)
                {
                    vis[x+1][y][z]=step;
                    q.push(pair<int,pair<int,int> >(x+1,pair<int,int>(y,z)));
                }
                if (x-1>=0&&rem[x-1][y][z]!='#'&&vis[x-1][y][z]==0)
                {
                    vis[x-1][y][z]=step;
                    q.push(pair<int,pair<int,int> >(x-1,pair<int,int>(y,z)));
                }
                if (y+1<m&&rem[x][y+1][z]!='#'&&vis[x][y+1][z]==0)
                {
                    vis[x][y+1][z]=step;
                    q.push(pair<int,pair<int,int> >(x,pair<int,int>(y+1,z)));
                }
                if (y-1>=0&&rem[x][y-1][z]!='#'&&vis[x][y-1][z]==0)
                {
                    vis[x][y-1][z]=step;
                    q.push(pair<int,pair<int,int> >(x,pair<int,int>(y-1,z)));
                }
                if (z+1<o&&rem[x][y][z+1]!='#'&&vis[x][y][z+1]==0)
                {
                    vis[x][y][z+1]=step;
                    q.push(pair<int,pair<int,int> >(x,pair<int,int>(y,z+1)));
                }
                if (z-1>=0&&rem[x][y][z-1]!='#'&&vis[x][y][z-1]==0)
                {
                    vis[x][y][z-1]=step;
                    q.push(pair<int,pair<int,int> >(x,pair<int,int>(y,z-1)));
                }
                q.pop();
                if (vis[x2][y2][z2]!=0)break;
            }
            if (vis[x2][y2][z2]!=0)break;
            step++;
        }
        if (vis[x2][y2][z2]==0)
        {
            printf ("Trapped!\n");
        }
        else printf ("Escaped in %d minute(s).\n",vis[x2][y2][z2]);
    }
}

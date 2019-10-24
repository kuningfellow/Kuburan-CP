//UVA 929 Number Maze
#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n,m;
        cin>>n>>m;
        int ma[n][m];
        int cost[n][m];
        int done[n][m];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                scanf("%d",&ma[i][j]);
                cost[i][j]=(1<<30)-1;
                done[i][j]=0;
            }
        }
        priority_queue<pair<int,pair<int,int> > >dik;
        dik.push(pair<int,pair<int,int> >(-ma[0][0],pair<int,int>(0,0)));
        int curcost;
        cost[0][0]=ma[0][0];
        int x,y;
        while (!dik.empty())
        {
            x=dik.top().second.first;
            y=dik.top().second.second;
            curcost=-dik.top().first;
            dik.pop();
            if (done[x][y]==1)continue;
            done[x][y]=1;
            if (x+1<n)
            {
                if (curcost+ma[x+1][y]<cost[x+1][y])
                {
                    cost[x+1][y]=curcost+ma[x+1][y];
                    dik.push(pair<int,pair<int,int> >(-cost[x+1][y],pair<int,int>(x+1,y)));
                }
            }
            if (y+1<m)
            {
                if (curcost+ma[x][y+1]<cost[x][y+1])
                {
                    cost[x][y+1]=curcost+ma[x][y+1];
                    dik.push(pair<int,pair<int,int> >(-cost[x][y+1],pair<int,int>(x,y+1)));
                }
            }
            if (x-1>=0)
            {
                if (curcost+ma[x-1][y]<cost[x-1][y])
                {
                    cost[x-1][y]=curcost+ma[x-1][y];
                    dik.push(pair<int,pair<int,int> >(-cost[x-1][y],pair<int,int>(x-1,y)));
                }
            }
            if (y-1>=0)
            {
                if (curcost+ma[x][y-1]<cost[x][y-1])
                {
                    cost[x][y-1]=curcost+ma[x][y-1];
                    dik.push(pair<int,pair<int,int> >(-cost[x][y-1],pair<int,int>(x,y-1)));
                }
            }
        }
        printf ("%d\n",cost[n-1][m-1]);
    }
}

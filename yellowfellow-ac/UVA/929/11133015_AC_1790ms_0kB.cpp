#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        priority_queue<pair< int, pair<int,int> > >pri;
        int ma[n][m];
        int cost[n][m];
        int done[n][m];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                done[i][j]=0;
                cost[i][j]=1000000000;
                cin>>ma[i][j];
            }
        }
        int x=0;
        int y=0;
        cost[x][y]=ma[x][y];
        done[x][y]=1;
        while (done[n-1][m-1]==0)
        {
            if (x+1<n)
            {
                cost[x+1][y]=min(cost[x+1][y],cost[x][y]+ma[x+1][y]);
                pri.push(pair<int,pair<int, int> >(-cost[x+1][y],pair <int, int> (x+1,y)));
            }
            if (x-1>=0)
            {
                cost[x-1][y]=min(cost[x-1][y],cost[x][y]+ma[x-1][y]);
                pri.push(pair<int,pair<int,int> >(-cost[x-1][y],pair <int, int> (x-1,y)));
            }
            if (y+1<m)
            {
                cost[x][y+1]=min(cost[x][y+1],cost[x][y]+ma[x][y+1]);
                pri.push(pair<int,pair<int,int> >(-cost[x][y+1],pair<int,int> (x,y+1)));
            }
            if (y-1>=0)
            {
                cost[x][y-1]=min(cost[x][y-1],cost[x][y]+ma[x][y-1]);
                pri.push(pair<int,pair<int,int> >(-cost[x][y-1],pair<int,int> (x,y-1)));
            }
            done[x][y]=1;
            do{
            x=pri.top().second.first;
            y=pri.top().second.second;
            pri.pop();
            }
            while (done[x][y]==1);
            done[x][y]=1;
        }
        printf ("%d\n",cost[n-1][m-1]);
    }
}

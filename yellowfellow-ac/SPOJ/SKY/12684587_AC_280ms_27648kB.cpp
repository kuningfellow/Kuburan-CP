#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long long int con[1005][1005];
int vis[1005][1005];
int n;
int x1,y1,x2,y2;
int fil(int h)
{
    queue<pair<int,int> >q;
    q.push(pair<int,int>(x1,y1));
    int l;
    int x,y;
    while (!q.empty())
    {
        l=q.size();
        for (int i=0;i<l;i++)
        {
            x=q.front().first;
            y=q.front().second;
            if (x+1<n&&vis[x+1][y]==0&&con[x+1][y]>=h)
            {
                q.push(pair<int,int>(x+1,y));
                vis[x+1][y]=1;
            }
            if (y+1<n&&vis[x][y+1]==0&&con[x][y+1]>=h)
            {
                q.push(pair<int,int>(x,y+1));
                vis[x][y+1]=1;
            }
            if (x-1>=0&&vis[x-1][y]==0&&con[x-1][y]>=h)
            {
                q.push(pair<int,int>(x-1,y));
                vis[x-1][y]=1;
            }
            if (y-1>=0&&vis[x][y-1]==0&&con[x][y-1]>=h)
            {
                q.push(pair<int,int>(x,y-1));
                vis[x][y-1]=1;
            }
            q.pop();
            if (vis[x2][y2]==1)break;
        }
        if (vis[x2][y2]==1)break;
    }
    if (vis[x2][y2]==1)return 1;
    return 0;
}
int main()
{
    cin>>n;
    cin>>x1>>y1>>x2>>y2;
    x1--;
    y1--;
    x2--;
    y2--;
    long long int a,b,c;
    cin>>a>>b>>c;
    long long int l=(1<<30),r=0,mid,ans;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            con[i][j]=((i*n+j)*a+b)%c;
            if (con[i][j]>r)r=con[i][j];
            if (con[i][j]<l)l=con[i][j];
        }
    }
    int yes;
    while (l<=r)
    {
        mid=(l+r)/2;
        for (int i=0;i<n;i++)
        {
        	for (int j=0;j<n;j++)
        	{
        		vis[i][j]=0;
			}
		}
        yes=0;
        if (con[x1][y1]>=mid)
            yes=fil(mid);
        if (yes)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    printf ("%lld\n",max(con[x1][y1]-ans,ans-con[x1][y1])+max(con[x2][y2]-ans,ans-con[x2][y2]));
}
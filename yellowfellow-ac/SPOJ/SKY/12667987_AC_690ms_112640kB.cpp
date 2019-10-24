#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
long long int con[1005][1005];
int vis[1005][1005];
int n;
int step;
void fil(int x,int y, int h)
{
    vis[x][y]=step;
    if (x+1<n&&vis[x+1][y]!=step&&con[x+1][y]>=h)
        fil(x+1,y,h);
    if (y+1<n&&vis[x][y+1]!=step&&con[x][y+1]>=h)
        fil(x,y+1,h);
    if (x-1>=0&&vis[x-1][y]!=step&con[x-1][y]>=h)
        fil(x-1,y,h);
    if (y-1>=0&&vis[x][y-1]!=step&&con[x][y-1]>=h)
        fil(x,y-1,h);
}
int main()
{
    cin>>n;
    int x1,y1,x2,y2;
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
    while (l<=r)
    {
        mid=(l+r)/2;
        step++;
        if (con[x1][y1]>=mid)
            fil(x1,y1,mid);
        if (vis[x2][y2]==step)
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

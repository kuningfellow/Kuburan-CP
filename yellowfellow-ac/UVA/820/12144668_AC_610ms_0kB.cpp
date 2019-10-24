#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int cap[105][105];
int flow[105][105];
int visit[105][105];
int rech[105];
int n;
int start,endd;
void reset()
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            visit[i][j]=0;
        }
    }
}
int serc(int x, int mi)
{
    if (x==endd)
    {
        return mi;
    }
    int mode=0;
    int maxi=0;
    int red;
    for (int i=0;i<n;i++)
    {
        if (cap[x][i]-flow[x][i]>0&&visit[x][i]==0)
        {
            visit[x][i]=1;
            visit[i][x]=1;
            red=serc(i,min(cap[x][i]-flow[x][i],mi));
            mi-=red;
            flow[x][i]+=red;
            flow[i][x]-=red;
            maxi+=red;
        }
    }
    return maxi;
}
int fin()
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            flow[i][j]=0;
        }
    }
    int ret=0;
    int cur=0;
    int temp=2;
    while (temp>0)
    {
        reset();
        temp=serc(start,(1<<30)-1);
        cur+=temp;
        if (cur>ret)ret=cur;
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cap[i][j]=0;
        }
    }
    return ret;
}
int main()
{
    int e,a,b,c,kas=1;
    while (1<2)
    {
        scanf("%d",&n);
        if (n==0)break;
        scanf("%d%d",&start,&endd);
        scanf("%d",&e);
        start--;
        endd--;
        for (int i=0;i<e;i++)
        {
            cin>>a>>b>>c;
            a--;
            b--;
            cap[a][b]+=c;
            cap[b][a]+=c;
        }
        printf ("Network %d\nThe bandwidth is %d.\n\n",kas++,fin());
    }
}

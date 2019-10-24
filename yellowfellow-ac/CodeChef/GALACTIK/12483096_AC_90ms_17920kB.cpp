#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int par[100005];
int cost[100005];
int mark[100005];
int finpar(int x)
{
    if (par[x]==x)
    {
        return x;
    }
    return par[x]=finpar(par[x]);
}
int main()
{
    int n,m;
    int a,b;
    scanf("%d%d",&n,&m);
    for (int i=0;i<=n;i++)
    {
        par[i]=i;
        cost[i]=-1;
    }
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        par[finpar(a)]=finpar(b);
    }
    int dis=0;
    int best=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a);
        if (mark[finpar(i+1)]==0)
        {
            dis++;
            mark[finpar(i+1)]=1;
        }
        if (a>=0)
        {
            if (best==0)best=finpar(i+1);
            else
            {
                if (cost[finpar(best)]>a)
                {
                    best=finpar(i+1);
                }
            }
            if (cost[finpar(i+1)]==-1)cost[finpar(i+1)]=a;
            else cost[finpar(i+1)]=min(cost[finpar(i+1)],a);
        }
    }
    int thot=0;
    dis--;
    for (int i=0;i<n;i++)
    {
        if (finpar(i+1)!=best&&mark[finpar(i+1)]==1&&cost[finpar(i+1)]>=0)
        {
            dis--;
            mark[finpar(i+1)]=0;
            thot+=cost[finpar(i+1)]+cost[finpar(best)];
        }
    }
    if (dis!=0)printf ("-1\n");
    else printf ("%d\n",thot);
}

//UVA 10048 Audiophobia
//kruskal's minimum spanning tree
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define ei second.first
#define be second.second
#define db first
using namespace std;
typedef pair<int,int> pii;
int par[105];
int vis[105];
vector<pair<int,pii> >mst;
int n;
int fil(int p, int t, int c)
{
    vis[p]=1;
    if (p==t)
    {
        return c;
    }
    int ret=-1;
    for (int i=0;i<mst.size();i++)
    {
        if (mst[i].ei==p&&vis[mst[i].be]==0)
        {
            ret=fil(mst[i].be,t,max(c,mst[i].db));
        }
        else if (mst[i].be==p&&vis[mst[i].ei]==0)
        {
            ret=fil(mst[i].ei,t,max(c,mst[i].db));
        }
        if (ret!=-1)break;
    }
    return ret;
}
int finpar(int x)
{
    if (par[x]!=x)
    {
        return par[x]=finpar(par[x]);
    }
    return par[x];
}
int main()
{
    int kas=1;
    while (1<2)
    {
        int e,q;
        cin>>n>>e>>q;
        if (n==0&&e==0&&q==0)
            break;
        for (int i=0;i<n;i++)
        {
            par[i]=i;
        }
        vector<pair<int ,pii> >edg;
        mst.clear();
        int a,b,c;
        for (int i=0;i<e;i++)
        {
            cin>>a>>b>>c;
            edg.push_back(pair<int ,pii>(c,pii(a-1,b-1)));
        }
        sort(edg.begin(),edg.end());
        for (int i=0;i<e;i++)
        {
            if (finpar(edg[i].ei)!=finpar(edg[i].be))
            {
                mst.push_back(pair<int ,pii> (edg[i].db, pii (edg[i].ei,edg[i].be) ) );
                par[par[edg[i].ei]]=par[edg[i].be];
            }
        }
        if (kas>1)printf ("\n");
        printf ("Case #%d\n",kas++);
        for (int i=0;i<q;i++)
        {
            cin>>a>>b;
            for (int i=0;i<n;i++)
                vis[i]=0;
            c=fil(a-1,b-1,0);
            if (c==-1)printf ("no path\n");
            else printf ("%d\n",c);
        }
    }
}

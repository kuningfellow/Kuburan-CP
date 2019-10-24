//UVA 10099 The Tourist Guide
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int se[105];
int finpar(int x)
{
    if (x==se[x])return x;
    if (x!=se[x])
    return se[x]=finpar(se[x]);
}
int check(int x, int y)
{
    int a=finpar(x);
    int b=finpar(y);
    if (a!=b)
    {
        se[a]=b;
        finpar(x);
        return 1;
    }
    else return 0;
}
int main()
{
    int kas=1;
    while (1<2)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0&&m==0)break;
        vector<pair<int,pair<int,int> > >ar;
        int a,b,c;
        for (int i=0;i<n+1;i++)
        {
            se[i]=i;
        }
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            ar.push_back(pair<int,pair<int,int> >(c,pair<int,int>(a,b)));
        }
        sort(ar.begin(),ar.end());
        int sta,en,ppl;
        scanf("%d%d%d",&sta,&en,&ppl);
        vector<pair<int, pair<int,int> > >mst;
        for (int i=m-1;i>=0;i--)
        {
            if (check(ar[i].second.first,ar[i].second.second))
            {
                mst.push_back(pair<int,pair<int,int> >(ar[i].first,pair<int,int>(ar[i].second.first,ar[i].second.second)));
            }
        }
        int visit[n+1];
        for (int i=0;i<n+1;i++)visit[i]=0;
        queue<pair<int,int> >q;
        q.push(pair<int,int>(sta,(1<<30)-1));
        while (!q.empty())
        {
            int siz=q.size();
            for (int i=0;i<siz;i++)
            {
                int x=q.front().first;
                for (int j=0;j<mst.size();j++)
                {
                    if (mst[j].second.first==x&&visit[mst[j].second.second]==0)
                    {
                        visit[mst[j].second.second]=max(visit[mst[j].second.second],min(q.front().second,mst[j].first));
                        q.push(pair<int,int>(mst[j].second.second,min(q.front().second,mst[j].first)));
                    }
                    if (mst[j].second.second==x&&visit[mst[j].second.first]==0)
                    {
                        visit[mst[j].second.first]=max(visit[mst[j].second.first],min(q.front().second,mst[j].first));
                        q.push(pair<int,int>(mst[j].second.first,min(q.front().second,mst[j].first)));
                    }
                }
                q.pop();
            }
        }
        printf ("Scenario #%d\n",kas++);
        printf ("Minimum Number of Trips = %d\n\n",ppl/(visit[en]-1)+(ppl%(visit[en]-1)>0));
    }
}

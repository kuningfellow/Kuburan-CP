#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int par[200005];
int finpar(int x)
{
    if (par[x]==x)
        return x;
    return par[x]=finpar(par[x]);
}
vector<pair<int,pair<int,int> > >lis;
int main()
{
    int n,m;
    while (1<2)
    {
        scanf("%d%d",&m,&n);
        if (m==0&&n==0)break;
        for (int i=0;i<m;i++)
        {
            par[i]=i;
        }
        int a,b,c;
        int co=0;
        int tot=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            tot+=c;
            lis.push_back(pair<int,pair<int,int> >(c,pair<int,int>(a,b)));
        }
        sort(lis.begin(),lis.end());
        for (int i=0;i<n;i++)
        {
            a=lis[i].second.first;
            b=lis[i].second.second;
            c=lis[i].first;
            if (finpar(a)!=finpar(b))
            {
                par[finpar(a)]=finpar(b);
                co+=c;
            }
        }
        printf ("%d\n",tot-co);
        lis.clear();
    }
}

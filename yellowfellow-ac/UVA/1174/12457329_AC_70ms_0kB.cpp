#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int par[2005];
int finpar(int x)
{
    if (x==par[x])return x;
    return par[x]=finpar(par[x]);
}
int main()
{
    int tc,fir=0;
    cin>>tc;
    map<string,int>cor;
    vector<pair<int,pair<int,int> > >lis;
    while (tc--)
    {
        int n,m;
        cin>>n>>m;
        for (int i=0;i<=n;i++)
        {
            par[i]=i;
        }
        string rem,ram;
        int c;
        int siz=1;
        for (int i=0;i<m;i++)
        {
            cin>>rem>>ram;
            cin>>c;
            if (cor[rem]==0)
                cor[rem]=siz++;
            if (cor[ram]==0)
                cor[ram]=siz++;
            lis.push_back(pair<int,pair<int,int> >(c,pair<int,int>(cor[rem],cor[ram])));
        }
        sort(lis.begin(),lis.end());
        c=0;
        for (int i=0;i<m;i++)
        {
            if (finpar(lis[i].second.first)!=finpar(lis[i].second.second))
            {
                par[finpar(lis[i].second.first)]=finpar(lis[i].second.second);
                c+=lis[i].first;
            }
        }
        if (fir==1)printf ("\n");
        fir=1;
        printf ("%d\n",c);
        cor.clear();
        lis.clear();
    }
}

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int par[500005];
int finpar(int x)
{
    if (par[x]==x)
        return x;
    return par[x]=finpar(par[x]);
}
vector<pair<int,int> >lis;
vector<pair<double,pair<int,int> > >con;
double dis(int a, int b)
{
    return sqrt((long long int)(lis[a].first-lis[b].first)*
                (lis[a].first-lis[b].first)+
                (long long int)(lis[a].second-lis[b].second)*
                (lis[a].second-lis[b].second));
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        int a,b;
        int siz=0;
        while (1<2)
        {
            cin>>a;
            if (a==-1)break;
            cin>>b;
            lis.push_back(pair<int,int>(a,b));
            siz++;
        }
        for (int i=0;i<siz;i++)
        {
            for (int j=i;j<siz;j++)
            {
                if (i==j)continue;
                con.push_back(pair<double,pair<int,int> >(dis(i,j),pair<int,int>(i,j)));
            }
        }
        int l=con.size();
        for (int i=0;i<l;i++)
        {
            par[i]=i;
        }
        double cost=0;
        sort(con.begin(),con.end());
        vector<double>take;
        for (int i=0;i<l;i++)
        {
            if (finpar(con[i].second.first)!=finpar(con[i].second.second))
            {
                par[finpar(con[i].second.first)]=finpar(con[i].second.second);
                take.push_back(con[i].first);
            }
        }
        l=siz-1;
        l-=(n-1);
        cost=take[l-1];
        printf ("%.0f\n",ceil(cost));
        lis.clear();
        con.clear();
    }
}

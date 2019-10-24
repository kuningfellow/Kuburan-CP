#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int par[105];
int finpar(int x)
{
    if (par[x]==x)return x;
    return par[x]=finpar(par[x]);
}
vector<pair<double,double> >node;
vector<pair<double,pair<int,int> > >con;
double dis(int a, int b)
{
    return sqrt((double)(node[a].first-node[b].first)*
                (node[a].first-node[b].first)+
                (double)(node[a].second-node[b].second)*
                (node[a].second-node[b].second));
}
int main()
{
    int tc,fir=0;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            par[i]=i;
        }
        double a,b;
        for (int i=0;i<n;i++)
        {
            cin>>a>>b;
            node.push_back(pair<double,double>(a,b));
        }
        for (int i=0;i<n;i++)
        {
            for (int j=i;j<n;j++)
            {
                con.push_back(pair<double,pair<int,int> >(dis(i,j),pair<int,int>(i,j)));
            }
        }
        int l=con.size();
        sort(con.begin(),con.end());
        double thot=0;
        for (int i=0;i<l;i++)
        {
            if (finpar(con[i].second.first)!=finpar(con[i].second.second))
            {
                par[finpar(con[i].second.first)]=finpar(con[i].second.second);
                thot+=con[i].first;
            }
        }
        if (fir==1)printf("\n");
        fir=1;
        printf ("%.2f\n",thot);
        con.clear();
        node.clear();
    }
}

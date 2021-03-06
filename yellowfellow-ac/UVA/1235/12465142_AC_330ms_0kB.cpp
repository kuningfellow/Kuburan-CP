#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int par[1000];
int finpar(int x)
{
    if (par[x]==x)return x;
    return par[x]=finpar(par[x]);
}
int ara[4];
int arb[4];
int dis(int a, int b)
{
    int k=3;
    while (k>=0)
    {
        ara[k]=a%10;
        a/=10;
        k--;
    }
    k=3;
    while (k>=0)
    {
        arb[k]=b%10;
        b/=10;
        k--;
    }
    k=0;
    int t;
    for (int i=0;i<4;i++)
    {
        if (ara[i]>arb[i])
        {
            k+=min(ara[i]-arb[i],10-(ara[i]-arb[i]));
        }
        else
        {
            k+=min(arb[i]-ara[i],10-(arb[i]-ara[i]));
        }
    }
    return k;
}
pair<int,pair<int,int> > lis[250005];
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        int num[n];
        for (int i=0;i<n;i++)
        {
            par[i]=i;
            cin>>num[i];
        }
        int siz=0;
        int add=10000;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (i==j)continue;
                lis[siz].first=dis(num[i],num[j]);
                lis[siz].second.first=i;
                lis[siz].second.second=j;
                siz++;
            }
            add=min(add,dis(num[i],0));
        }
        sort(lis,lis+siz);
        for (int i=0;i<siz;i++)
        {
            if (finpar(lis[i].second.first)!=finpar(lis[i].second.second))
            {
                par[finpar(lis[i].second.first)]=finpar(lis[i].second.second);
                add+=lis[i].first;
            }
        }
        printf ("%d\n",add);
    }
}

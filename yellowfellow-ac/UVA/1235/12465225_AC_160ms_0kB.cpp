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
    int ret=0;
    int x,y;
    while (k>=0)
    {
        x=a%10;
        y=b%10;
        if (x>y)
        {
            ret+=min(x-y,10-(x-y));
        }
        else
        {
            ret+=min(y-x,10-(y-x));
        }
        a/=10;
        b/=10;
        k--;
    }
    return ret;
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
            for (int j=i+1;j<n;j++)
            {
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

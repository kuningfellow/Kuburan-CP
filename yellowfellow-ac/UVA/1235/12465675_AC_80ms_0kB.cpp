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
struct mst
{
    bool operator < (const mst &o)const{
    if (val<o.val)return true;
    return false;
    }
    int val;
    int a;
    int b;
};
struct mst lis[250005];
bool cmp(struct mst &left, struct mst &right)
{
    if (left.val<right.val)
    {
        return 1;
    }
    return 0;
}
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
                lis[siz].val=dis(num[i],num[j]);
                lis[siz].a=i;
                lis[siz].b=j;
                siz++;
            }
            add=min(add,dis(num[i],0));
        }
        sort(lis,lis+siz);
        for (int i=0;i<siz;i++)
        {
            if (finpar(lis[i].a)!=finpar(lis[i].b))
            {
                par[finpar(lis[i].a)]=finpar(lis[i].b);
                add+=lis[i].val;
            }
        }
        printf ("%d\n",add);
    }
}


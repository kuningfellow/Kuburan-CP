#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int par[100005];
int on[100005];
long long int ma[100005];
int finpar(int x)
{
    if (par[x]==x)return x;
    return par[x]=finpar(par[x]);
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n,m;
        cin>>n>>m;
        for (int i=1;i<=n;i++)
        {
            par[i]=i;
            ma[i]=0;
            on[i]=0;
        }
        int a,b;
        for (int i=0;i<m;i++)
        {
            cin>>a>>b;
            if (finpar(a)!=finpar(b))
            {
                par[finpar(a)]=finpar(b);
            }
        }
        int co=0;
        for (int i=1;i<=n;i++)
        {
            ma[finpar(i)]++;
            if (on[finpar(i)]==0)
            {
                co++;
            }
            on[finpar(i)]=1;
        }
        long long int way=1;
        for (int i=1;i<=n;i++)
        {
            if (on[i]==1)
            {
                way*=ma[i];
                way%=1000000007;
            }
        }
        printf ("%d %lld\n",co,way);
    }
}

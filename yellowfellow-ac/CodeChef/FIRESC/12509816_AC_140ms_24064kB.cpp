#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int>lis[100005];
int vis[100005];
long long int way;
long long int temp=0;
int co;
void serc(int x)
{
    vis[x]=1;
    temp++;
    for (int i=0;i<lis[x].size();i++)
    {
        if (vis[lis[x][i]]==0)
            serc(lis[x][i]);
    }
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while (tc--)
    {
        int n,m,a,b;
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++)
            vis[i]=0;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            lis[a-1].push_back(b-1);
            lis[b-1].push_back(a-1);
        }
        co=0;
        way=1;
        for (int i=0;i<n;i++)
        {
            if (vis[i]==0)
            {
                co++;
                temp=0;
                serc(i);
                way*=temp;
                way%=1000000007;
            }
        }
        printf ("%d %lld\n",co,way);
        for (int i=0;i<n;i++)
        {
            lis[i].clear();
        }
    }
}

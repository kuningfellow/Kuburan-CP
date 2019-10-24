//UVA 11749 Poor Trade Advisor
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int n;
long long int maxi;
long long int ar[505][505];
int ir[505][505];
int vis[505];
int serc (int x)
{
    vis[x]=1;
    int ret=1;
    for (int i=0;i<n;i++)
    {
        if (ir[x][i]==1&&ar[x][i]==maxi&&vis[i]==0)
        {
            ret+=serc(i);
        }
    }
    return ret;
}
int main()
{
    while (1<2)
    {
        int a,b,m;
        long long int c;
        cin>>n>>m;
        if (n==0&&m==0)break;
        maxi;
        int un=0;
        for (int i=0;i<n;i++)
        {
            vis[i]=0;
            for (int j=0;j<n;j++)
            {
                ir[i][j]=0;
            }
        }
        for (int i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            if (ir[a-1][b-1]==1)
            {
                ar[a-1][b-1]=max(ar[a-1][b-1],c);
                ar[b-1][a-1]=max(ar[b-1][a-1],c);
            }
            else
            {
                ar[a-1][b-1]=c;
                ar[b-1][a-1]=c;
            }
            ir[a-1][b-1]=1;
            ir[b-1][a-1]=1;
            if (un==0||c>maxi)
            {
                un=1;
                maxi=c;
            }
        }
        int ans=0,res;
        for (int i=0;i<n;i++)
        {
            if (vis[i]==0)
            {
                res=serc(i);
                if (res>ans)ans=res;
            }
        }
        printf ("%d\n",ans);
    }
}

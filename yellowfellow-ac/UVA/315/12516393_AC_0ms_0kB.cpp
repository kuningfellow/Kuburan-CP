//UVA 315 Network
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n;
int low[105];
int num[105];
int vis[105];
int con[105][105];
int cut;
int co;
void serc(int p, int x)
{
    vis[x]=1;
    num[x]=co;
    low[x]=co++;
    int val=0;
    int rat=0;
    for (int i=0;i<n;i++)
    {
        if (con[x][i]==1)
        {
            if (vis[i]==0)
            {
                val++;
                serc(x,i);
                if (i!=p)
                {
                    if (num[x]<=low[i])
                    {
                        rat=1;
                    }
                    low[x]=min(low[x],low[i]);
                }
            }
            else if (i!=p)
            {
                low[x]=min(low[x],num[i]);
            }
        }
    }
    if (x==p&&val>1&&rat==1)cut++;
    if (x!=p&&rat==1)cut++;
}
int main()
{
    while (1<2)
    {
        cin>>n;
        if (n==0)break;
        for (int i=0;i<n;i++)
        {
            vis[i]=0;
            for (int j=0;j<n;j++)
            {
                con[i][j]=0;
            }
        }
        co=0;
        cut=0;
        int a,b;
        getchar();
        char rem[500];
        while (1<2)
        {
            scanf("%[^\n]",rem);
            getchar();
            int l=strlen(rem);
            if (l==1&&rem[0]=='0')break;
            b=0;
            int flag=0;
            for (int i=0;i<l;i++)
            {
                if (rem[i]>='0'&&rem[i]<='9')
                {
                    b*=10;
                    b+=rem[i]-'0';
                }
                else
                {
                    if (flag==0)
                    {
                        a=b;
                        flag=1;
                    }
                    else
                    {
                        con[a-1][b-1]=1;
                        con[b-1][a-1]=1;
                    }
                    b=0;
                }
            }
            if (b>0)
            {
                con[a-1][b-1]=1;
                con[b-1][a-1]=1;
            }
        }
        for (int i=0;i<n;i++)
        {
            if (vis[i]==0)
            {
                serc(i,i);
            }
        }
        printf ("%d\n",cut);
    }
}

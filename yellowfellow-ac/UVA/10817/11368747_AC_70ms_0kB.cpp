#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int>t[2];
vector<int>nt[2];
int dp[(1<<16)][105];
int s,m,n;
int addify(int mask1, int mask2)
{
    int tem=0;
    while (mask2>0)
    {
        if (mask2%2==1)
        {
            if ((mask1&(1<<tem))==0)
            {
                mask1|=(1<<tem);
            }
            else mask1|=(1<<(tem+s));
        }
        tem++;
        mask2/=2;
    }
    return mask1;
}
int sear (int smask, int x)
{
    if (smask==(1<<(s*2))-1)
    {
        return 0;
    }
    else if (x==n)
    {
        return 10000000;
    }
    if (dp[smask][x]!=-1)
    {
        return dp[smask][x];
    }
    int a=sear(smask,x+1);
    int misk=addify(smask,nt[1][x]);
    int b=nt[0][x]+sear(misk,x+1);
    dp[smask][x]=min(a,b);
    return dp[smask][x];
}
int main()
{
    while (1<2)
    {
        cin>>s>>m>>n;
        if (s==0)break;
        char lis[50];
        int pri;
        int monet=0;
        char c;
        int mask;
        for (int i=0;i<m;i++)
        {
            scanf("%d",&pri);
            getchar();
            c='0';
            monet+=pri;
            int k=0;
            int temp;
            while (c!='\n')
            {
                c=getchar();
                lis[k]=c;
                k++;
            }
            mask=0;
            t[0].push_back(pri);
            mask=0;
            for (int j=0;j<k-1;j++)
            {
                if (lis[j]>='0'&&lis[j]<='9')
                {
                    temp=lis[j]-'0'-1;
                    mask|=(1<<temp);
                }
            }
            t[1].push_back(mask);
        }
        for (int i=0;i<n;i++)
        {
            scanf("%d",&pri);
            getchar();
            c='0';
            int k=0;
            int temp;
            while (c!='\n')
            {
                c=getchar();
                lis[k]=c;
                k++;
            }
            mask=0;
            nt[0].push_back(pri);
            for (int j=0;j<k-1;j++)
            {
                if (lis[j]>='0'&&lis[j]<='9')
                {
                    temp=lis[j]-'0'-1;
                    mask|=(1<<temp);
                }
            }
            nt[1].push_back(mask);
        }
        int misk=0;
        int dp3=0;
        for (int i=0;i<(1<<(s*2));i++)
        {
            for (int j=0;j<n;j++)
            {
                dp[i][j]=-1;
            }
        }
        for(int i=0;i<m;i++)
        {
            dp3+=t[0][i];
            misk=addify(misk,t[1][i]);
        }
        cout<<dp3+sear(misk,0)<<endl;
        t[0].clear();
        t[1].clear();
        nt[0].clear();
        nt[1].clear();
    }
}

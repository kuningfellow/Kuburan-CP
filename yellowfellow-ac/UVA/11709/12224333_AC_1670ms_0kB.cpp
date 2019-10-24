#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
using namespace std;
int con[2005][2005];
int bel[2005];
int num[2005];
int visit[2005];
int n;
int cir;
int par(int x)
{
    if (bel[x]==-1||bel[x]==x)
    {
        return num[x];
    }
    if (num[x]!=bel[x])
    {
        return bel[x]=par(bel[x]);
    }
}
stack<int>st;
int co;
void serc(int p)
{
    num[p]=co++;
    bel[p]=num[p];
    visit[p]=1;
    st.push(p);
    for (int i=0;i<n;i++)
    {
        if (con[p][i]==1)
        {
            if (num[i]==-1)
            {
                serc(i);
            }
            if (visit[i]==1)
            {
                bel[p]=min(bel[p],bel[i]);
            }
        }
    }
    if (num[p]==bel[p])
    {
        cir++;
        while (1<2)
        {
            int v=st.top();
            st.pop();
            visit[v]=0;
            if (v==p)break;
        }
    }
}
void res()
{
    for (int i=0;i<n;i++)
    {
        num[i]=-1;
    }
}
int main()
{
	while (1<2)
	{
		int edge;
		cin>>n>>edge;
		if (n==0&&edge==0)
		{
			break;
		}
		getchar();
		int a,b;
		char nam[n][500];
		char rem[500];
		char ram[500];
		for (int i=0;i<n;i++)
		{
			scanf("%[^\n]",nam[i]);
			getchar();
		}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				con[i][j]=0;
			}
		}
		for (int i=0;i<edge;i++)
		{
			scanf("%[^\n]",rem);
			getchar();
			scanf("%[^\n]",ram);
			getchar();
			for (int j=0;j<n;j++)
			{
				if (!strcmp(nam[j],rem))
				{
					a=j;
					break;
				}
			}
			for (int j=0;j<n;j++)
			{
				if (!strcmp(nam[j],ram))
				{
					b=j;
					break;
				}
			}
			con[a][b]=1;
		}
		for (int i=0;i<n;i++)
        {
            visit[i]=0;
            num[i]=-1;
            bel[i]=-1;
        }
		co=0;
		for (int i=0;i<n;i++)
		{
			if (num[i]==-1)
			{
			    serc(i);
			}
		}
		printf ("%d\n",cir);
		cir=0;
	}
}

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int bac[105];
int vis[105];
int star,en;
int flow[105][105];
void bfs()
{
	queue<int>q;
	q.push(star);
	bac[q.front()]=-1;
	vis[star]=1;
	int siz;
	while (!q.empty())
	{
		siz=q.size();
		for (int i=0;i<siz;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (vis[j]==0&&flow[q.front()][j]>0)
				{
					vis[j]=1;
					bac[j]=q.front();
					q.push(j);
				}
			}
			q.pop();
			if (vis[en]==1)break;
		}
		if (vis[en]==1)break;
	}
}
int flowe()
{
	int sum=0;
	while (1<2)
	{
		for (int i=0;i<n;i++)
		{
			vis[i]=0;
		}
		bfs();
		if (vis[en]==0)break;
		int red=(1<<30);
		vector<int>lis;
		int x=en;
		while (x!=star)
		{
			red=min(red,flow[bac[x]][x]);
			lis.push_back(x);
			x=bac[x];
		}
		sum+=red;
		lis.push_back(star);
		for (int i=lis.size()-1;i>0;i--)
		{
			flow[lis[i]][lis[i-1]]-=red;
			flow[lis[i-1]][lis[i]]+=red;
		}
	}
	return sum;
}
int main()
{
	int kas=1;
	while (1<2)
	{
		cin>>n;
		if (n==0)break;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				flow[i][j]=0;
			}
		}
		int k;
		cin>>star>>en>>k;
		star--;
		en--;
		int a,b,c;
		for (int i=0;i<k;i++)
		{
			cin>>a>>b>>c;
			flow[a-1][b-1]+=c;
			flow[b-1][a-1]+=c;
		}
		printf ("Network %d\nThe bandwidth is %d.\n\n",kas++,flowe());
	}
}
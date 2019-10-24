#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while (tc--)
	{
		int n,m;
		cin>>n>>m;
		vector<int>lis[n];
		int vis[n];
		for (int i=0;i<n;i++)vis[i]=0;
		int a,b;
		for (int i=0;i<m;i++)
		{
			cin>>a>>b;
			lis[a].push_back(b);
			lis[b].push_back(a);
		}
		queue<int>q;
		q.push(0);
		int step=1;
		int siz;
		vis[0]=1;
		while (!q.empty())
		{
			siz=q.size();
			for (int i=0;i<siz;i++)
			{
				for (int j=0;j<lis[q.front()].size();j++)
				{
					if (vis[lis[q.front()][j]]==0)
					{
						vis[lis[q.front()][j]]=step;
						q.push(lis[q.front()][j]);
					}
				}
				q.pop();
			}
			step++;
		}
		for (int i=1;i<n;i++)
		{
			printf ("%d\n",vis[i]);
		}
		if (tc!=0)printf ("\n");
	}
}
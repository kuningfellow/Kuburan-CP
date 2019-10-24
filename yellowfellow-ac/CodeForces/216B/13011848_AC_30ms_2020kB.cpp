#include<bits/stdc++.h>
using namespace std;

bool out[105];
bool visit[105];
bool color[105];
queue<int> pos;
vector<int> adj[105];
int bicolor(int n)
{
	pos.push(n);
	visit[n]=1;
	int ret=0;
	while(!pos.empty())
	{
		int u=pos.front();
		pos.pop();
		if(out[u]) continue;
		for(int z=0;z<adj[u].size();z++)
		{
			int v=adj[u][z];
			if(!visit[v])
			{
				visit[v]=1;
				color[v]=(color[u]^1);
				pos.push(v);
			}
			else if(!out[v])
			{
				if(color[v]==color[u])
				{
					out[v]=1;
					ret++;
				}
			}
		}
	}
	return ret;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for(int a=1;a<=N;a++)
	{
		adj[a].clear();
	}
	for(int a=0;a<M;a++)
	{
		int L, R;
		scanf("%d %d", &L, &R);
		adj[L].push_back(R);
		adj[R].push_back(L);
	}
	int hasil=0;
	for(int a=1;a<=N;a++)
	{
		if(visit[a]) continue;
		hasil+=bicolor(a);
	}
	if((N-hasil)%2==1)
	{
		hasil++;
	}
	printf("%d\n", hasil);
	return 0;
}
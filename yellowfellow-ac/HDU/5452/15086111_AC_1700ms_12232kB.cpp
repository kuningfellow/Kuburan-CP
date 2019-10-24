#include<iostream>
#include<stdio.h>
#include<vector>
#include<utility>
#include<map>
using namespace std;
typedef pair<int, int> pii;
int dg[200005];
vector<int> adj[200005];
map<pii, bool> isi;
int getmin(int a, int b)
{
	if(a > b) return b;
	return a;
}
int main()
{
	int tc;
	scanf("%d", &tc);
	for(int ntc=1;ntc<=tc;ntc++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		isi.clear();
		for(int a=1;a<=n;a++)
		{
			adj[a].clear();
		}
		for(int a=0;a<m;a++)
		{
			int L, R;
			scanf("%d%d", &L, &R);
			adj[L].push_back(R);
			adj[R].push_back(L);
			if(a < n-1)
			{
				isi[pii(L, R)]=1;
				isi[pii(R, L)]=1;
			}
		}
		int mini=1e9;
		for(int a=1;a<=n;a++)
		{
			int dg=adj[a].size(), cnt=0;
			for(int z=0;z<adj[a].size();z++)
			{
				int L=a, R=adj[a][z];
				if(isi.count(pii(L, R)) > 0) cnt++;
			}
			if(cnt>=2) continue;
			mini=getmin(mini, dg);
		}
		printf("Case #%d: %d\n", ntc, mini);
	}
	return 0;
}
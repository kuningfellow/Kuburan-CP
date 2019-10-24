#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
priority_queue<pii> pos;
int n, need, m;
vector<pair<int, pii> > adj[1005];
bool visit[1005];

int dj(int sec)
{
	for(int a=1;a<=n;a++) visit[a]=0;
	pos.push(pii(0, 1));
	while(!pos.empty())
	{
		int nowcost=-pos.top().fi, u=pos.top().se;
		if(u==n)
		{
			while(!pos.empty()) pos.pop();
			return nowcost;
		}
		pos.pop();
		if(visit[u]) continue;
		visit[u]=1;
		for(int z=0;z<adj[u].size();z++)
		{
			int nc=nowcost+adj[u][z].se.fi, v=adj[u][z].fi, lvl=adj[u][z].se.se;
			if(!visit[v] && lvl <= sec)
			{
				pos.push(pii(-nc, v));
			}
		}
	}
	return 2000000000;
}

int bins(int L, int R, int tmp)
{
	if(L > R) return tmp;
	int mid=(L+R)/2;
	int hasil=dj(mid);
	if(hasil <= need)
	{
		return bins(L, mid-1, mid);
	}
	else
	{
		return bins(mid+1, R, tmp);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int a=0;a<m;a++)
	{
		int l, r, w, lvl;
		scanf("%d%d%d%d", &l, &r, &w, &lvl);
		adj[l].pb(pair<int, pii> (r, pii(w, lvl)));
		
		adj[r].pb(pair<int, pii> (l, pii(w, lvl)));
	}
	scanf("%d", &need);
	int hasil=bins(1, 1000000, 1000000);
	int output=dj(hasil);
	if(output>need)
	{
		printf("NO");
	}
	else
	{
		printf("YES\n");
		printf("%d %d", hasil, output);
	}
	printf("\n");
	return 0;
}
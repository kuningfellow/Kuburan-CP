//SPOJ FASTFLOW Fast Maximum Flow
//Dinic
#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
struct edge {
	int v, b;
	LL f;
};
vector<edge> lis[5005];
int vis[5005];
int st[5005];
int n;
void addedge(int a, int b, int c) {
	int ba = lis[b].size();
	int bb = lis[a].size();
	edge A = {b, ba, c};
	edge B = {a, bb, c};
	lis[a].push_back(A);
	lis[b].push_back(B);
}
int bfs() {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		st[i] = 0;
		vis[i] = -1;
	}
	vis[0] = 0;
	q.push(0);
	while (!q.empty() && vis[n-1] == -1) {
		int siz = q.size();
		for (int i = 0; i < siz; i++) {
			int v = q.front();
			q.pop();
			for (int j = 0; j < lis[v].size(); j++) {
				if (lis[v][j].f > 0 && vis[lis[v][j].v] == -1) {
					vis[lis[v][j].v] = vis[v] + 1;
					q.push(lis[v][j].v);
				}
			}
		}
	}
	return vis[n-1];
}
LL dfs(int x, LL car) {
	if (x == n - 1) {
		return car;
	}
	for (int i = st[x]; i < lis[x].size() && car > 0; i++) {
		st[x] = i;
		if (lis[x][i].f > 0 && vis[lis[x][i].v] == vis[x] + 1) {
			LL ret = dfs(lis[x][i].v, min(car, lis[x][i].f));
			if (ret > 0) {
				lis[x][i].f -= ret;
				lis[lis[x][i].v][lis[x][i].b].f += ret;
				return ret;
			}
		}
	}
	return 0;
}
LL maxflow() {
	LL ans = 0;
	while (1 < 2) {
		int d = bfs();
		if (d == -1) break;
		LL ret;
		while (ret = dfs(0, (-1) ^ (1ll << 63))) {
			ans += ret;
			if (ret == 0) break;
		}
	}
	return ans;
}
int main() {
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		addedge(a, b, c);
	}
	printf("%lld\n", maxflow());
	return 0;
}
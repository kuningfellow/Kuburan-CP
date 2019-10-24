//SPOJ GREED Greedy Island
//tag: Minimum Cost Flow Problem
//solution: SAP (Shortest Augmenting Path) using Bellman Ford
#include<bits/stdc++.h>
using namespace std;
const int N = 502;
const int MAX = (1 << 30);

struct edge {
	int v, b, f, c;
};

vector<edge> lis[N];
pair<int,int> bac[N];
int vis[N];
int cnt[N];

void addedge(int a, int b, int f, int c) {
	edge A = {b, lis[b].size(), f, c};
	edge B = {a, lis[a].size(), 0, -c};
	lis[a].push_back(A);
	lis[b].push_back(B);
}

void bellman(int n) {
	for (int i = 0; i <= n; i++) {
		vis[i] = MAX;
	}
	vis[0] = 0;
	for (int i = 1; i <= n; i++) {
		int alter = 0;
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k < lis[j].size(); k++) {
				if (lis[j][k].f > 0 && vis[j] + lis[j][k].c < vis[lis[j][k].v]) {
					alter = 1;
					vis[lis[j][k].v] = vis[j] + lis[j][k].c;
					bac[lis[j][k].v].first = j;
					bac[lis[j][k].v].second = k;
				}
			}
		}
		if (alter == 0) break;
	}
}

pair<int,int> augment(int n) {
	bellman(n);
	if (vis[n] == MAX) return pair<int,int>(0, 0);
	vector<pair<int,int> > bt;
	int x = bac[n].first;
	int k = bac[n].second;
	bt.push_back(pair<int,int>(x, k));
	int flow = lis[x][k].f;
	while (x != 0) {
		k = bac[x].second;
		x = bac[x].first;
		flow = min(flow, lis[x][k].f);
		bt.push_back(pair<int,int>(x, k));
	}
	int cost = 0;
	for (int i = bt.size()-1; i >= 0; i--) {
		x = bt[i].first;
		k = bt[i].second;
		cost += lis[x][k].c * flow;
		lis[x][k].f -= flow;
		lis[lis[x][k].v][lis[x][k].b].f += flow;
	}
	return pair<int,int>(flow, cost);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			cnt[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			cnt[a]++;
		}
		n++;
		for (int i = 0; i <= n; i++) {
			lis[i].clear();
		}
		for (int i = 1; i < n; i++) {
			if (cnt[i] > 0) addedge(0, i, cnt[i], 0);
			addedge(i, n, 1, 0);
		}
		int e;
		scanf("%d", &e);
		while (e--) {
			int a, b;
			scanf("%d%d", &a, &b);
			addedge(a, b, MAX, 1);
			addedge(b, a, MAX, 1);
		}
		pair<int,int> ans;
		ans.first = 0;
		ans.second = 0;
		while (1 < 2) {
			pair<int,int> ret = augment(n);
			if (ret.first == 0) break;
			ans.first += ret.first;
			ans.second += ret.second;
		}
		printf("%d\n", ans.second);
	}
}
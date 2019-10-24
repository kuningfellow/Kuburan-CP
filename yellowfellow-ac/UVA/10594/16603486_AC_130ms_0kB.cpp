//UVA 10594 Data Flow
#include<bits/stdc++.h>
using namespace std;
const int N = 102;
typedef long long int LL;
const LL MAX = (1ll << 62);
struct edge {
	int v, b;
	LL f, c;
};

vector<edge> lis[N];
vector<pair<int, pair<int,int> > > edg;
pair<int,int> bac[N];
LL vis[N];
LL cnt[N];
int n;
void addedge(int a, int b, LL f, LL c) {
	edge A = {b, lis[b].size(), f, c};
	edge B = {a, lis[a].size(), 0, -c};
	lis[a].push_back(A);
	lis[b].push_back(B);
}

void bellman() {
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

pair<LL,LL> augment() {
	bellman();
	if (vis[n] == MAX) return pair<LL,LL>(0, 0);
	vector<pair<int,int> > bt;
	int x = bac[n].first;
	int k = bac[n].second;
	bt.push_back(pair<int,int>(x, k));
	LL flow = lis[x][k].f;
	while (x != 0) {
		k = bac[x].second;
		x = bac[x].first;
		flow = min(flow, lis[x][k].f);
		bt.push_back(pair<int,int>(x, k));
	}
	LL cost = 0;
	for (int i = bt.size()-1; i >= 0; i--) {
		x = bt[i].first;
		k = bt[i].second;
		cost += lis[x][k].c * flow;
		lis[x][k].f -= flow;
		lis[lis[x][k].v][lis[x][k].b].f += flow;
	}
	return pair<LL,LL>(flow, cost);
}

int main() {
	int m;
	while(scanf("%d%d", &n, &m) != EOF) {
		edg.clear();
		for (int i = 0; i <= n; i++) {
			lis[i].clear();
		}
		for (int i = 0; i < m; i++) {
			pair<int,pair<int,int> >dum;
			scanf("%d%d%d", &dum.second.first, &dum.second.second, &dum.first);
			edg.push_back(dum);
		}
		LL d, k;
		scanf("%lld%lld", &d, &k);
		for (int i = 0; i < edg.size(); i++) {
			addedge(edg[i].second.first, edg[i].second.second, k, edg[i].first);
			addedge(edg[i].second.second, edg[i].second.first, k, edg[i].first);
		}
		addedge(0, 1, d, 0);
		pair<LL,LL> ans;
		ans.first = 0;
		ans.second = 0;
		while (1 < 2) {
			pair<LL,LL> ret = augment();
			if (ret.first == 0) break;
			ans.first += ret.first;
			ans.second += ret.second;
		}
		if (ans.first != d) printf("Impossible.\n");
		else printf("%lld\n", ans.second);
	}
}
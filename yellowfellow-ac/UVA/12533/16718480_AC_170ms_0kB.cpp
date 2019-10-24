//UVA 12533 Joining Couples
#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int logN = 18;
int T[N];
vector<int> lis[N];
int low[N], num[N], vis[N], deg[N], D[N], ord[N], siz[N];
int lca[logN][N];
int rlca[logN][N];
stack<int>st;
int IDX, P;
void tarj(int x) {
	vis[x] = 1;
	low[x] = num[x] = IDX++;
	st.push(x);
	if (num[T[x]] == -1) tarj(T[x]);
	if (vis[T[x]] == 1) low[x] = min(low[x], low[T[x]]);
	if (low[x] == num[x]) {
		while (1 < 2) {
			int v = st.top();
			st.pop();
			vis[v] = 0;
			siz[low[v]]++;
			low[v] = low[x];
			if (v == x) break;
		}
	}
}
void order(int x, int p) {
	vis[x] = 1;
	ord[x] = p;
	if (low[T[x]] == low[x] && vis[T[x]] == 0) order(T[x], p + 1);
}
void parify(int x, int d, int p) {
	vis[x] = 1;
	D[x] = d;
	lca[0][x] = p;
	for (int i = 0; i < lis[x].size(); i++) {
		if (lis[x][i] != p) {
			parify(lis[x][i], d + 1, x);
		}
	}
}
void parify2(int x, int d, int p) {
	vis[x] = 1;
	rlca[0][x] = p;
	for (int i = 0; i < lis[x].size(); i++) {
		if (lis[x][i] != p) {
			parify2(lis[x][i], d + 1, x);
		}
	}
}
void Blca(int n) {
	P = 0;
	while ((1 << P) < n) P++;
	for (int i = 1; i <= P; i++) {
		for (int j = 0; j <= n; j++) {
			lca[i][j] = lca[i - 1][lca[i - 1][j]];
			rlca[i][j] = rlca[i - 1][rlca[i - 1][j]];
		}
	}
}
int getlca(int a, int b) {
	if (D[a] < D[b]) a ^= b ^= a ^= b;
	int delta = D[a] - D[b];
	for (int i = 0; i <= P; i++) {
		if (delta & (1 << i)) {
			a = lca[i][a];
		}
	}
	if (a == b) return a;
	for (int i = P; i >= 0; i--) {
		if (lca[i][a] != lca[i][b]) {
			a = lca[i][a];
			b = lca[i][b];
		}
	}
	return lca[0][a] == lca[0][b] ? lca[0][a] : -1;
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i <= n; i++) {
			lis[i].clear();
			num[i] = low[i] = -1;
			vis[i] = deg[i] = 0;
			siz[i] = D[i] = ord[i] = 0;
		}
		IDX = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &T[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (num[i] == -1) {
				tarj(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0) order(i, 0);
		}
		for (int i = 1; i <= n; i++) {
			if (low[i] != low[T[i]]) {
				lis[low[T[i]]].push_back(low[i]);
				deg[low[i]]++;
			}
			vis[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			if (vis[low[i]] == 0 && deg[low[i]] == 0) {
				parify(low[i], 0, low[i]);
			}
		}
		for (int i = 1; i <= n; i++) {
			lis[i].clear();
			deg[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			if (low[i] != low[T[i]]) {
				lis[T[i]].push_back(i);
				deg[i]++;
			}
			vis[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0 && deg[i] == 0) {
				parify2(i, 0, i);
			}
		}
		Blca(n);
		int q;
		scanf("%d", &q);
		while (q--) {
			int a, b;
			scanf("%d%d", &a, &b);
			int c = getlca(low[a], low[b]);
			if (c == -1) printf("-1\n");
			else {
				int cost = abs(D[low[a]] - D[c]) + abs(D[low[b]] - D[c]);
				if (low[b] != c) {
					int delta = D[low[b]] - 1 - D[c];
					for (int i = P; i >= 0; i--) {
						if (delta & (1 << i)) {
							b = rlca[i][b];
						}
					}
					b = rlca[0][b];
				}
				if (low[a] != c) {
					int delta = D[low[a]] - 1 - D[c];
					for (int i = P; i >= 0; i--) {
						if (delta & (1 << i)) {
							a = rlca[i][a];
						}
					}
					a = rlca[0][a];
				}
				if (low[a] == low[b]) {
					cost += min(abs(ord[a] - ord[b]), siz[low[a]] - abs(ord[a] - ord[b]));
				}
				printf("%d\n", cost);
			}
		}
	}
}
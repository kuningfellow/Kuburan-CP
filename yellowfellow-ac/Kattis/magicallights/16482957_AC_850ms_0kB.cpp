#include<bits/stdc++.h>
using namespace std;
struct dat {
	long long int stat[2];
	dat() {
		stat[0] = 0;
		stat[1] = 0;
	}
};
dat tree[1200005];
int subsiz[300005];
int color[300005];
int ntot[300005];
vector<int> lis[300005];
int idx;
int dfs(int x, int par) {
	ntot[x] = idx++;
	int ret = 0;
	for (int i = 0; i < lis[x].size(); i++) {
		if (lis[x][i] != par) ret += dfs(lis[x][i], x);
	}
	subsiz[x] = ret;
	return ret+1;
}
void update(int k, int l, int r, int p, int c) {
	if (l > p || r < p) return;
	if (l == r) {
		int s = 0;
		if (c >= 50) s = 1, c-=50;
		tree[k].stat[s] ^= (1ll<<c);
		return;
	}
	update(k*2, l, (l+r)/2, p, c);
	update(k*2+1, (l+r)/2+1, r, p, c);
	tree[k].stat[0] = tree[k*2].stat[0] ^ tree[k*2+1].stat[0];
	tree[k].stat[1] = tree[k*2].stat[1] ^ tree[k*2+1].stat[1];
}
dat query(int k, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {
		return tree[k];
	}
	if (ql > r || qr < l) {
		dat dum;
		dum.stat[0] = 0;
		dum.stat[1] = 0;
		return dum;
	}
	dat left = query(k*2, l, (l+r)/2, ql, qr);
	dat right = query(k*2+1, (l+r)/2+1, r, ql, qr);
	left.stat[0] = left.stat[0] ^ right.stat[0];
	left.stat[1] = left.stat[1] ^ right.stat[1];
	return left;
}
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &color[i]);
		color[i]--;
	}
	for (int i = 1; i < n; i++) {
		int a;
		scanf("%d", &a);
		a--;
		lis[a].push_back(i);
		lis[i].push_back(a);
	}
	dfs(0, 0);
	for (int i = 0; i < n; i++) {
		update(1, 0, n-1, ntot[i], color[i]);
	}
	for (int i = 0; i < q; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == 0) {
			dat ret = query(1, 0, n-1, ntot[b-1], ntot[b-1] + subsiz[b-1]);
			int ans = 0;
			while (ret.stat[0] > 0) {
				if (ret.stat[0] % 2 == 1) ans++;
				ret.stat[0] /= 2;
			}
			while (ret.stat[1] > 0) {
				if (ret.stat[1] % 2 == 1) ans++;
				ret.stat[1] /= 2;
			}
			printf("%d\n", ans);
		}
		else {
			update(1, 0, n-1, ntot[b-1], color[b-1]);
			color[b-1] = a-1;
			update(1, 0, n-1, ntot[b-1], color[b-1]);
		}
	}
}
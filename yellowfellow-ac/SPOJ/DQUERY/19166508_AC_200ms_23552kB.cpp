#include<stdio.h>
#include<vector>

using namespace std;

namespace ST {
	int tree[1 << 16];
	void init(int k, int l, int r) {
		tree[k] = 0;
		if (l != r) {
			init(k*2, l, (l+r)/2);
			init(k*2+1, (l+r)/2+1, r);
			tree[k] = tree[k*2] + tree[k*2+1];
		}
	}
	void update(int k, int l, int r, int p, int v) {
		if (l == r) tree[k] += v;
		else {
			if (p <= (l+r)/2) update(k*2, l, (l+r)/2, p, v);
			else update(k*2+1, (l+r)/2+1, r, p, v);
			tree[k] = tree[k*2] + tree[k*2+1];
		}
	}
	int query(int k, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) return tree[k];
		else if (l > qr || r < ql) return 0;
		return query(k*2, l, (l+r)/2, ql, qr) + query(k*2+1, (l+r)/2+1, r, ql, qr);
	}
}

int vis[1000005];
vector<pair<int,int> > query[30005];
int ar[30005];
int ans[200005];

int main() {
	int n;
	scanf("%d", &n);
	ST::init(1, 0, n-1);
	for (int i = 0; i < 1000005; i++) {
		vis[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		query[r-1].push_back(pair<int,int>(i, l-1));
	}
	for (int i = 0; i < n; i++) {
		if (vis[ar[i]] != -1){
			ST::update(1, 0, n-1, vis[ar[i]], -1);
		}
		vis[ar[i]] = i;
		ST::update(1, 0, n-1, vis[ar[i]], 1);
		for (int j = 0; j < query[i].size(); j++) {
			ans[query[i][j].first] = ST::query(1, 0, n-1, query[i][j].second, i);
		}
	}
	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
	
}
#include<bits/stdc++.h>
using namespace std;
int tree[500005];
int cnt[100005];

vector<int> v[100005];

struct dat {
	int p, f;
	bool operator<(const dat& a) {
		if (p != a.p) return p < a.p;
		else return f < a.f;
	}
};
void update(int k, int l, int r, int p, int v) {
	if (r < p || l > p) return;
	if (l == r) {
		tree[k] += v;
		return;
	}
	update(k*2, l, (l+r)/2, p, v);
	update(k*2+1, (l+r)/2+1, r, p, v);
	tree[k] = tree[k*2] + tree[k*2+1];
}
int query(int k, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return tree[k];
	if (ql > r || l > qr) return 0;
	return query(k*2, l, (l+r)/2, ql, qr) + query(k*2+1, (l+r)/2+1, r, ql, qr);
}
vector<dat> lis;
vector<pair<int,int> > segs;
int main() {
	int n;
	scanf("%d", &n);
	dat dum;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		dum.p = a;
		dum.f = 1;
		lis.push_back(dum);
		dum.p = b;
		dum.f = 0;
		lis.push_back(dum);
		update(1, 0, 100004, a, 1);
		segs.push_back(pair<int,int>(a, b));
	}
	sort(lis.begin(), lis.end());
	int car = 0;
	for (int i = 0; i < 100005; i++) {
		cnt[i] = -1;
	}
	int ans2 = 0;
	for (int i = 0; i < lis.size(); i++) {
		if (lis[i].f == 1) car++;
		if (lis[i].f == 0) car--;
		cnt[lis[i].p] = car;
		ans2 = max(ans2, cnt[lis[i].p]);
	}
	int ans = 0;
	for (int i = 0; i < segs.size(); i++) {
		ans = max(ans, cnt[segs[i].first] + query(1, 0, 100004, segs[i].first+1, 100004)
			- query(1, 0, 100004, segs[i].second, 100004));
	}
	printf("%d %d\n", ans, ans2);
}
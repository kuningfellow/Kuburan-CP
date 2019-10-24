#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int E = (-1) ^  (1 << 31);
int tree[N * 4];
int lazy[N * 4];
void update(int k, int l, int r, int ql, int qr, int v){
	if (lazy[k] != 0){
		tree[k] |= lazy[k];
		if (l != r){
			lazy[k * 2] |= lazy[k];
			lazy[k * 2 + 1] |= lazy[k];
		}
		lazy[k] = 0;
	}
	if (ql <= l && r <= qr) {
		tree[k] |= v;
		lazy[k] |= v;
	}
	else if (l > qr || r < ql) {
		return;
	}
	else {
		update(k*2, l, (l+r)/2, ql, qr, v);
		update(k*2+1, (l+r)/2+1, r, ql, qr, v);
		tree[k] = tree[k*2] & tree[k*2+1];
	}
}
int query(int k, int l, int r, int ql, int qr){
	if (lazy[k] != 0){
		tree[k] |= lazy[k];
		if (l != r){
			lazy[k * 2] |= lazy[k];
			lazy[k * 2 + 1] |= lazy[k];
		}
		lazy[k] = 0;
	}
	if (ql <= l && r <= qr) {
		return tree[k];
	}
	else if (l > qr || r < ql) {
		return E;
	}
	else {
		return query(k*2, l, (l+r)/2, ql, qr) & query(k*2+1, (l+r)/2+1, r, ql, qr);
	}
}
vector<int> lis;
void flat(int k, int l, int r){
	if (lazy[k] != 0){
		tree[k] |= lazy[k];
		if (l != r){
			lazy[k * 2] |= lazy[k];
			lazy[k * 2 + 1] |= lazy[k];
		}
		lazy[k] = 0;
	}
	if (l == r){
		lis.push_back(tree[k]);
	}
	else {
		flat(k*2, l, (l+r)/2);
		flat(k*2+1, (l+r)/2+1, r);
	}
}
vector<pair<pair<int,int>,int> > eval;
int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; i++) {
		int l, r, v;
		scanf("%d%d%d", &l, &r, &v);
		update(1, 0, n-1, l-1, r-1, v);
		eval.push_back(pair<pair<int,int>,int>(pair<int,int>(l, r), v));
	}
	int val = 1;
	for (int i = 0; i < q; i++) {
		if (query(1, 0, n-1, eval[i].first.first - 1, eval[i].first.second - 1) != eval[i].second){
			val = 0;
			break;
		}
	}
	if (val){
		flat(1, 0, n-1);
		printf("YES\n");
		for (int i = 0; i < n; i++) {
			printf("%d ", lis[i]);
		}
		printf("\n");
	}
	else {
		printf("NO\n");
	}
}
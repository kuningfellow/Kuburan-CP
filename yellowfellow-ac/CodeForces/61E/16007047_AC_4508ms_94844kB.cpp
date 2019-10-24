#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int N = 1000001;
LL tree[N*3];
LL tree2[N*3];
LL dp[N];
int ar[N];
map<int,int>cor;
vector<int> lis;
void update(LL* tr, int k, int l, int r, int p, LL v){
	if (l == r) {
		if (l == p) {
			tr[k] += v;
		}
		return;
	}
	if (l > p || r < p) {
		return;
	}
	update(tr, k*2, l, (l+r)/2, p, v);
	update(tr, k*2+1, (l+r)/2+1, r, p, v);
	tr[k] = tr[k*2] + tr[k*2+1];
}
LL query(LL* tr, int k, int l, int r, int ql, int qr){
	if (ql > qr){
		return 0;
	}
	if (ql <= l && r <= qr) {
		return tr[k];
	}
	if (l > qr || r < ql) {
		return 0;
	}
	return query(tr, k*2, l, (l+r)/2, ql, qr) + query(tr, k*2+1, (l+r)/2+1, r, ql, qr);
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
		if (cor[ar[i]] == 0){
			lis.push_back(ar[i]);
			cor[ar[i]] = 1;
		}
	}
	cor.clear();
	int id = 0;
	sort(lis.begin(), lis.end());
	for (int i = 0; i < lis.size(); i++) {
		cor[lis[i]] = id++;
	}
	for (int i = n-1; i >= 0; i--) {
		dp[i] = query(tree, 1, 0, n-1, 0, cor[ar[i]] - 1);
		update(tree, 1, 0, n-1, cor[ar[i]], 1);
	}
	LL ans = 0;
	for (int i = n-1; i >= 0; i--) {
		if (i < n-1){
			ans += query(tree2, 1, 0, n-1, 0, cor[ar[i]] - 1);
		}
		update(tree2, 1, 0, n-1, cor[ar[i]], dp[i]);
	}
	printf("%lld\n", ans);
}
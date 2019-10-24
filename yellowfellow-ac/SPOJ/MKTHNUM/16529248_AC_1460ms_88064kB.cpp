#include<bits/stdc++.h>
using namespace std;
struct tree {
	int val;
	tree* left;
	tree* right;
};
tree* ver[100005];
void updatep(tree* k, tree* nk, int l, int r, int p, int v) {
	nk->left = k->left;
	nk->right = k->right;
	nk->val = k->val;
	if (l > p || r < p) return;
	if (l == r) {
		nk->val += v;
		return;
	}
	int mid = (l + r) / 2;
	if (p <= mid) nk->left = (tree*)malloc(sizeof(tree));
	else nk->right = (tree*)malloc(sizeof(tree));
	updatep(k->left, nk->left, l, mid, p, v);
	updatep(k->right, nk->right, mid+1, r, p, v);
	nk->val = nk->left->val + nk->right->val;
}
int queryp(tree* k, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return k->val;
	if (ql > r || l > qr) return 0;
	return queryp(k->left, l, (l+r)/2, ql, qr) + queryp(k->right, (l+r)/2+1, r, ql, qr);
}
void init(tree* k, int l, int r) {
	k->val = 0;
	if (l == r) return;
	k->left = (tree*)malloc(sizeof(tree));
	k->right = (tree*)malloc(sizeof(tree));
	init(k->left, l, (l+r)/2);
	init(k->right, (l+r)/2+1, r);
}
int serc(tree* k, tree* K, int l, int r, int v) {
	if (l == r) {
		return l;
	}
	if (K->left->val - k->left->val >= v) {
		return serc(k->left, K->left, l, (l+r)/2, v);
	}
	else {
		return serc(k->right, K->right, (l+r)/2+1, r, v-(K->left->val - k->left->val));
	}
}
map<int,int> vtot;
map<int,int> ttov;
vector<int> comp;
int ar[100005];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	ver[0] = (tree*)malloc(sizeof(tree));
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
		comp.push_back(ar[i]);
	}
	sort(comp.begin(), comp.end());
	vtot[comp[0]] = 0;
	ttov[0] = comp[0];
	int siz = 1;
	for (int i = 1; i < n; i++) {
		if (comp[i] != comp[i-1]) {
			vtot[comp[i]] = 1 + vtot[comp[i-1]];
			ttov[vtot[comp[i]]] = comp[i];
			siz++;
		}
	}
	init(ver[0], 0, siz-1);
	for (int i = 0; i < n; i++) {
		ver[i+1] = (tree*)malloc(sizeof(tree));
		updatep(ver[i], ver[i+1], 0, siz-1, vtot[ar[i]], 1);
	}
	for (int j = 0; j < m; j++) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", ttov[serc(ver[l-1], ver[r], 0, siz-1, k)]);
	}
}
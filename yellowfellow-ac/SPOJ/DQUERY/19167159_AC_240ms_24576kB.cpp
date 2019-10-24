#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

int sta[30005];

namespace PST {
	struct tree {
		int val;
		tree *L, *R;
	};
	tree* root[30005];
	tree* nnode() {
		tree* ret = (tree*)malloc(sizeof(tree));
		ret->val = 0;
		ret->L = ret->R = NULL;
		return ret;
	}
	void init(tree* node, int l, int r) {
		if (l != r) {
			node->L = nnode();
			node->R = nnode();
			init(node->L, l, (l+r)/2);
			init(node->R, (l+r)/2+1, r);
			node->val = node->L->val + node->R->val;
		}
		else if (sta[l] == 1) node->val = 1;
	}
	void update(tree* node, tree* prev, int l, int r, int p) {
		node->L = prev->L;
		node->R = prev->R;
		if (l == r) node->val = 1;
		else {
			if (p <= (l+r)/2) node->L = nnode(), update(node->L, prev->L, l, (l+r)/2, p);
			else node->R = nnode(), update(node->R, prev->R, (l+r)/2+1, r, p);
			node->val = node->L->val + node->R->val;
		}
	}
	int query(tree* node, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) return node->val;
		else if (l > qr || r < ql) return 0;
		return query(node->L, l, (l+r)/2, ql, qr) + query(node->R, (l+r)/2+1, r, ql, qr);
	}
}

int last[1000005];
int to[30005];
int ar[30005];

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < 1000001; i++) {
		last[i] = -1;
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
		to[i] = last[ar[i]];
		last[ar[i]] = i;
	}
	
	for (int i = 0; i < 1000001; i++) {
		if (last[i] != -1) {
			sta[last[i]] = 1;
		}
	}
	
	PST::root[n-1] = PST::nnode();
	init(PST::root[n-1], 0, n-1);
	
	for (int i = n - 2; i >= 0; i--) {
		PST::root[i] = PST::nnode();
		if (to[i+1] != -1) PST::update(PST::root[i], PST::root[i+1], 0, n-1, to[i+1]);
		else PST::root[i] = PST::root[i+1];
	}
	
	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", PST::query(PST::root[r-1], 0, n-1, l-1, r-1));
	}
	
	return 0;
}
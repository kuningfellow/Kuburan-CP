// Dquery PST without malloc and init efficient no nnode calls
#include<stdio.h>

using namespace std;

int sta[30005];

namespace PST {
	int tree[1000000][3];
	int ptr;
	void init(int node, int l, int r) {
		if (l != r) {
			tree[node][1] = ptr++;
			tree[node][2] = ptr++;
			init(tree[node][1], l, (l+r)/2);
			init(tree[node][2], (l+r)/2+1, r);
			tree[node][0] = tree[tree[node][1]][0] + tree[tree[node][2]][0];
		}
		else if (sta[l] == 1) tree[node][0] = 1;
		else tree[node][0] = 0;
	}
	void update(int node, int prev, int l, int r, int p) {
		tree[node][1] = tree[prev][1];
		tree[node][2] = tree[prev][2];
		if (l == r) tree[node][0] = 1;
		else {
			if (p <= (l+r)/2) tree[node][1] = ptr++, update(tree[node][1], tree[prev][1], l, (l+r)/2, p);
			else tree[node][2] = ptr++, update(tree[node][2], tree[prev][2], (l+r)/2+1, r, p);
			tree[node][0] = tree[tree[node][1]][0] + tree[tree[node][2]][0];
		}
	}
	int query(int node, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) return tree[node][0];
		else if (l > qr || r < ql) return 0;
		return query(tree[node][1], l, (l+r)/2, ql, qr) + query(tree[node][2], (l+r)/2+1, r, ql, qr);
	}
}

int last[1000005];
int to[30005];
int ar[30005];
int ver[30005];

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
	
	for (int i = n-1; i >= 0; i--) {
		if (last[ar[i]] != -1) {
			sta[last[ar[i]]] = 1;
			last[ar[i]] = -1;
		}
	}
	
	ver[n-1] = PST::ptr++;
	PST::init(ver[n-1], 0, n-1);
	
	for (int i = n - 2; i >= 0; i--) {
		ver[i] = PST::ptr++;
		if (to[i+1] != -1) PST::update(ver[i], ver[i+1], 0, n-1, to[i+1]);
		else ver[i] = ver[i+1];
	}
	
	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", PST::query(ver[r-1], 0, n-1, l-1, r-1));
	}
	
	return 0;
}
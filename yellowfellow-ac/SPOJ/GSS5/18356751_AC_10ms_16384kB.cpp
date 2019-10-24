#include<stdio.h>

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

struct dat {
	int sum, best, le, ri;
};

int ar[10005];
dat tree[1 << 15];
dat emptree;

dat combine(const dat& l, const dat& r) {
	dat ret;
	ret.sum = l.sum + r.sum;
	ret.le = max(l.le + r.sum, r.le);
	ret.ri = max(r.ri + l.sum, l.ri);
	ret.best = max(l.best, r.best);
	ret.best = max(l.le + r.ri, ret.best);
	return ret;
}

void build(int k, int l, int r) {
	if (l == r) {
		tree[k].best = tree[k].sum = tree[k].le = tree[k].ri = ar[l];
	}
	else {
		build(k * 2, l, (l + r) / 2);
		build(k * 2 + 1, (l + r) / 2 + 1, r);
		tree[k] = combine(tree[k * 2], tree[k * 2 + 1]);
	}
}

dat query(int k, int l, int r, int ql, int qr) {
	if (ql > qr) return emptree;
	else if (ql <= l && r <= qr) return tree[k];
	else if (ql > r || l > qr) return emptree;
	else return combine(query(k * 2, l, (l + r) / 2, ql, qr), query(k * 2 + 1, (l + r) / 2 + 1, r, ql, qr));
}

int main() {
	emptree.sum = 0;
	emptree.le = emptree.ri = emptree.best = -1000000000;
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &ar[i]);
		
		build(1, 0, n - 1);
		
		int q;
		scanf("%d", &q);
		
		while (q--) {
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			x1--, y1--, x2--, y2--;
			
			if (y1 < x2) {
				printf("%d\n", query(1, 0, n-1, y1+1, x2-1).sum +
								query(1, 0, n-1, x1, y1).le +
								query(1, 0, n-1, x2, y2).ri);
			}
			else {
				int a = query(1, 0, n-1, x1, y1).le + query(1, 0, n-1, y1, y2).ri - ar[y1];
				int b = query(1, 0, n-1, x1, x2).le + query(1, 0, n-1, x2, y2).ri - ar[x2];
				int c = query(1, 0, n-1, x2, y1).best;
				printf("%d\n", max(a, max(b, c)));
			}
		}
	}
	return 0;
}
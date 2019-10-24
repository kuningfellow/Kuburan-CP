// jebol mode
#include<stdio.h>
#include<utility>

typedef long long int LL;

LL sigma[2] = {31, 37};
LL mod[2] = {1000000009, 1000000003};
LL shifts[100005][2];

namespace ST {
	struct dat {
		int len;
		LL x1_l;
		LL x1_r;
		LL x2_l;
		LL x2_r;
	};
	dat tree[1 << 18];
	dat dum = {0, 0, 0, 0, 0};
	dat combine(dat L, dat R) {
		dat ret;
		ret.len = L.len + R.len;
		ret.x1_r = (L.x1_r + R.x1_r * shifts[L.len][0] % mod[0]) % mod[0];
		ret.x1_l = (L.x1_l * shifts[R.len][0] + R.x1_l) % mod[0];
		ret.x2_r = (L.x2_r + R.x2_r * shifts[L.len][1] % mod[1]) % mod[1];
		ret.x2_l = (L.x2_l * shifts[R.len][1]+ R.x2_l) % mod[1];
		return ret;
	}
	void update(int k, int l, int r, int p, int v) {
		if (l == r) {
			if (l == p) {
				tree[k].len = 1;
				tree[k].x1_l = tree[k].x1_r = tree[k].x2_l = tree[k].x2_r = v;
			}
			return;
		}
		else {
			if (p <= (l+r)/2) update(k*2, l, (l+r)/2, p, v);
			else update(k*2+1, (l+r)/2+1, r, p, v);
			tree[k] = combine(tree[k*2], tree[k*2+1]);
		}
	}
	dat query(int k, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) {
			return tree[k];
		}
		else if (l > qr || r < ql) {
			return dum;
		}
		else {
			return combine(query(k*2, l, (l+r)/2, ql, qr), query(k*2+1, (l+r)/2+1, r, ql, qr));
		}
	}
}

char str[100005];

int main() {
	shifts[0][0] = shifts[0][1] = 1;
	for (int i = 1; i < 100005; i++) {
		for (int j = 0; j < 2; j++) {
			shifts[i][j] = shifts[i-1][j] * sigma[j] % mod[j];
		}
	}
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, q;
		scanf("%d %d", &n, &q);
		scanf("%s", str);
		for (int i = 0; i < n; i++) {
			ST::update(1, 0, n-1, i, str[i] - 'a' + 1);
		}
		while (q--) {
			int type;
			scanf("%d", &type);
			if (type == 1) {
				int x;
				scanf("%d %s", &x, str);
				ST::update(1, 0, n-1, x-1, str[0] - 'a' + 1);
			}
			else {
				int l, r;
				scanf("%d %d", &l, &r);
				l--;
				r--;
				if (l == r) {
					printf("Adnan Wins\n", "");
				}
				else {
					int m1 = (l+r)/2, m2;
					if ((r-l)%2) m2 = m1+1;
					else m2 = m1 + 1, m1--;
					ST::dat le = ST::query(1, 0, n-1, l, m1);
					ST::dat ri = ST::query(1, 0, n-1, m2, r);
					if (le.x1_l == ri.x1_r) {
						printf("Adnan Wins\n");
					}
					else {
						printf("ARCNCD!\n");
					}
				}
			}
		}
	}
	return 0;
}
#include<bits/stdc++.h>

struct dat {
	int first, second;
	bool operator<(const dat& a) {
		if (first != a.first) return first < a.first;
		return second < a.second;
	}
};
dat ord[101];
char str[100][51];

namespace wygn {
	dat t1[101];
	dat t2[101];
	void merg(int l, int r) {
		int pl = l;
		int mid = (l + r) / 2;
		int pr = mid + 1;
		for (int i = l; i <= r; i++) {
			if (pl > mid) t2[i] = t1[pr++];
			else if (pr > r) t2[i] = t1[pl++];
			else if (t1[pl] < t1[pr]) t2[i] = t1[pl++];
			else t2[i] = t1[pr++];
		}
		for (int i = l; i <= r; i++) {
			t1[i] = t2[i];
		}
	}
	void divi(int l, int r) {
		if (l == r) return;
		int mid = (l + r) / 2;
		divi(l, mid);
		divi(mid+1, r);
		merg(l, r);
	}
	void sort(dat* a, int n) {
		for (int i = 0; i < n; i++) {
			t1[i] = a[i];
		}
		divi(0, n-1);
		for (int i = 0; i < n; i++) {
			a[i] = t1[i];
		}
	}
}
using namespace wygn;
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, m;
		scanf("%d%d", &n, &m);
		dat dum;
		for (int i = 0; i < m; i++) {
			scanf("%s", str[i]);
			dum.first = 0;
			dum.second = i;
			ord[i] = dum;
			for (int j = 0; j < n; j++) {
				for (int k = j+1; k < n; k++) {
					if (str[i][j] > str[i][k]) {
						ord[i].first++;
					}
				}
			}
		}
		wygn::sort(ord, m);
		for (int i = 0; i < m; i++) {
			printf("%s\n", str[ord[i].second]);
		}
		if (tc) printf("\n");
	}
}
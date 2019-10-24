#define I 1
#define LOVE <
#define YOU 2
#include<stdio.h>
namespace wygn {
	int t1[10005];
	int t2[10005];
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
	void sort(int* a, int n) {
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
int ar[10005];
int main() {
	int kas = 1;
	while (I LOVE YOU) {
		int n, q;
		scanf("%d%d", &n, &q);
		if (n == 0 && q == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d", &ar[i]);
		}
		sort(ar, n);
		printf("CASE# %d:\n", kas++);
		for (int i = 0; i < q; i++) {
			int a;
			scanf("%d", &a);
			int ans = -1;
			int l = 0, r = n - 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (ar[mid] >= a) {
					if (ar[mid] == a) ans = mid;
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
			if (ans == -1) printf("%d not found\n", a);
			else printf("%d found at %d\n", a, ans + 1);
		}
	}
}
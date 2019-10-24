#include<bits/stdc++.h>
using namespace std;
int ar[100005];
int bc[100005];
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &ar[i]);
		}
		int siz = 0;
		bc[0] = -10000000;
		for (int i = 0; i < n; i++) {
			int l = 0, r = siz;
			int ans = 0;
			while (l <= r) {
				int mid = (l+r)/2;
				if (bc[mid] <= ar[i]) {
					ans = mid;
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
			bc[ans + 1] = ar[i];
			siz = max(siz, ans + 1);
		}
		int val = 0;
		if (siz >= n-1) {
			val = 1;
		}
		bc[0] = 1000000;
		siz = 0;
		for (int i = 0; i < n; i++) {
			int l = 0, r = siz;
			int ans = 0;
			while (l <= r) {
				int mid = (l+r)/2;
				if (bc[mid] >= ar[i]) {
					ans = mid;
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
			bc[ans + 1] = ar[i];
			siz = max(siz, ans + 1);
		}
		if (siz >= n-1) {
			val = 1;
		}
		printf("%s\n", val?"YES":"NO");
	}
}
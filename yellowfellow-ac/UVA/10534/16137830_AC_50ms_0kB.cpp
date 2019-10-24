//UVA 10534 Wavio Sequence
#include<bits/stdc++.h>
using namespace std;
int ar[10005];
int cnt1[10005];
int cnt2[10005];
int lis[10005];
int lds[10005];
int main(){
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &ar[i]);
		}
		int m1 = 0;
		lis[0] = -1;
		for (int i = 0; i < n; i++) {
			int l = 0, r = m1;
			int found = 0;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (lis[mid] == -1 || ar[lis[mid]] < ar[i]) {
					found = mid;
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
			cnt1[i] = found;
			lis[found + 1] = i;
			m1 = max(m1, found + 1);
		}
		int m2 = 0;
		lds[0] = -1;
		for (int i = n-1; i >= 0; i--) {
			int l = 0, r = m2;
			int found = 0;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (lds[mid] == -1 || ar[lds[mid]] < ar[i]) {
					found = mid;
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
			cnt2[i] = found;
			lds[found + 1] = i;
			m2 = max(m2, found + 1);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, min(cnt1[i], cnt2[i])*2 + 1);
		}
		printf("%d\n", ans);
	}
}

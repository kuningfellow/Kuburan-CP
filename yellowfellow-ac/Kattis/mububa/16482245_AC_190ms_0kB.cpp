#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL ar[3005];
LL dp[3005][3005];
void serc(int l, int r, int optl, int optr, int k) {
	if (l > r) return;
	int mid = (l + r) / 2;
	int R = min(optr, mid);
	dp[k][mid] = (-1) ^ (1ll << 63);
	int opt = optl;
	for (int i = optl; i <= R; i++) {
		if (i-1 < 0) continue;
		if (dp[k-1][i-1] <= ar[mid] - ar[i-1]) {
			if (ar[mid] - ar[i-1] < dp[k][mid]) {
				dp[k][mid] = ar[mid] - ar[i-1];
				opt = i;
			}
		}
	}
	serc(l, mid-1, optl, opt, k);
	serc(mid+1, r, opt, optr, k);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &ar[i]);
		if (i > 0) ar[i] += ar[i-1];
	}
	for (int i = 0; i < n; i++) {
		dp[1][i] = ar[i];
	}
	for (int i = 2; i <= n; i++) {
		serc(0, n-1, 0, n-1, i);
	}
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		if (dp[i][n-1] != ((-1) ^ (1ll << 63))) ans = i;
		else break;
	}
	printf("%d\n", ans);
}
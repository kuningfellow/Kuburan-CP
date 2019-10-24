//CodeChef CHEFAOR Chef and Bitwise OR
//DP DNC
#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL cost[5001][5001];
LL dp[5001][5001];
int ar[5001];
void serc(int l, int r, int optl, int optr, int k) {
	if (l > r) {
		return;
	}
	int mid = (l + r) / 2;
	int opt = -1;
	int R = min(optr, mid);
	dp[k][mid] = 0;
	for (int i = optl; i <= R; i++) {
		if (i - 1 < 0) continue;
		if (dp[k-1][i-1] + cost[i][mid] > dp[k][mid]) {
			dp[k][mid] = dp[k-1][i-1] + cost[i][mid];
			opt = i;
		}
	}
	serc(l, mid-1, optl, opt, k);
	serc(mid+1, r, opt, optr, k);
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%d", &ar[i]);
		}
		for (int i = 0; i < n; i++) {
			int car = 0;
			for (int j = i; j < n; j++) {
				car |= ar[j];
				cost[i][j] = car;
			}
		}
		for (int i = 0; i < n; i++) {
			dp[1][i] = cost[0][i];
		}
		for (int i = 2; i <= k; i++) {
			serc(0, n-1, 0, n-1, i);
		}
		printf("%lld\n", dp[k][n-1]);
	}
}
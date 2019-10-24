#include<bits/stdc++.h>
using namespace std;
const int N = 2016;
int dp[N][2];
int ar[N];
int serc(int rem, int mode) {
	if (rem == 0) {
		return ar[mode];
	}
	if (dp[rem][mode] != -1) {
		return dp[rem][mode];
	}
	for (int i = 1; i <= rem; i++) {
		int rec = (i-1) * ar[1] + ar[mode+i] + serc(rem-i, 1);
		dp[rem][mode] = max(dp[rem][mode], rec);
	}
	return dp[rem][mode];
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i < n; i++) {
			scanf("%d", &ar[i]);
		}
		for (int i = 0; i < n; i++) {
			dp[i][0] = dp[i][1] = -1;
		}
		printf("%d\n", serc(n-1, 0));
	}
}
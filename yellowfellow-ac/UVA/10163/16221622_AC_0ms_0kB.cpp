//UVA 10163 Storage Keepers
//bottom up (difficult)
#include<bits/stdc++.h>
using namespace std;
int dp[105];
int ar[35];
int main(){
	while (1 < 2) {
		int n, m;
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;
		for (int i = 0; i < m; i++) {
			scanf("%d", &ar[i]);
		}
		for (int i = 1; i <= n; i++) {
			dp[i] = 0;
		}
		dp[0] = 1000;
		for (int i = 0; i < m; i++) {
			for (int j = n; j > 0; j--) {
				for (int k = 0; k < j; k++) {
					dp[j] = max(dp[j], min(ar[i]/(j-k), dp[k]));
				}
			}
		}
		int ans = dp[n];
		for (int i = 0; i <= n; i++) {
			dp[i] = 30000;
		}
		dp[0] = 0;
		for (int i = 0; i < m; i++) {
			for (int j = n; j > 0; j--) {
				for (int k = 1; k <= j; k++) {
					if (ar[i] / k >= ans){
						dp[j] = min(dp[j], ar[i] + dp[j-k]);
					}
				}
			}
		}
		if (ans == 0) {
			printf("0 0\n");
		}
		else {
			printf("%d %d\n", ans, dp[n]);
		}
	}
}
//UVA 10003 Cutting Sticks
//Knuth Yao version
#include<bits/stdc++.h>
using namespace std;
int opt[53][53];
int cost[53][53];
int dp[53][53];
int ar[53];
int main() {
	while (1 < 2) {
		int l, n;
		scanf("%d", &l);
		if (l == 0) break;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &ar[i]);
		}
		n++;
		ar[n] = l;
		for (int i = 0; i <= n; i++) {
			int car = 0;
			cost[i][i] = 0;
			dp[i][i] = (1 << 30);
			for (int j = i + 1; j <= n; j++) {
				car += ar[j] - ar[j-1];
				cost[i][j] = car;
				dp[i][j] = (1 << 30);
			}
		}
		for (int k = 0; k <= n; k++) {
			for (int i = 0; i + k <= n; i++) {
				if (k < 2) {
					dp[i][i+k] = 0;
					opt[i][i + k] = i;
				}
				else {
					int sta = opt[i][i + k - 1];
					int end = opt[i + 1][i + k];
					for (int j = sta; j <= end; j++) {
						if (dp[i][j] + dp[j][i + k] + cost[i][i + k] < dp[i][i + k]) {
							dp[i][i + k] = dp[i][j] + dp[j][i + k] + cost[i][i + k];
							opt[i][i + k] = j;
						}
					}
				}
			}
		}
		printf("The minimum cutting is %d.\n", dp[0][n]);
	}
	return 0;
}
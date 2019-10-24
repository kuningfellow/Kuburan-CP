#include<stdio.h>
int dist[11][11];
int dp[11][1 << 10];
int n;
int min(int a, int b) {
	if (a < b) return a;
	return b;
}
int serc(int x, int y) {
	if (y == (1 << n) - 1) {
		return dist[x][0];
	}
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = ~(1 << 31);
	for (int i = 0; i < n; i++) {
		if (y & (1 << i)) continue;
		dp[x][y] = min(dp[x][y], dist[x][i + 1] + serc(i + 1, y | (1 << i)));
	}
	return dp[x][y];
}
int main() {
	while (1 < 2) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				scanf("%d", &dist[i][j]);
			}
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				for (int k = 0; k <= n; k++) {
					dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
				}
			}
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < (1 << n); j++) {
				dp[i][j] = -1;
			}
		}
		printf("%d\n", serc(0, 0));
	}
	return 0;
}
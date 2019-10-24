#include<stdio.h>
typedef long long int LL;
LL sex[18][18];
LL ar[18];
int n, m;
LL dp[1 << 18][18];
int yey(int x) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (x & (1 << i)) cnt++;
	}
	if (cnt == m) return 1;
	return 0;
}
LL max(LL a, LL b) {
	if (a > b) return a;
	return b;
}
LL serc(int x, int y) {
	if (yey(x)) {
		return 0;
	}
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = (1ll << 63);
	for (int i = 0; i < n; i++) {
		if (x & (1 << i)) continue;
		dp[x][y] = max(dp[x][y], ar[i] + (x ? sex[y][i] : 0) + serc(x | (1 << i), i));
	}
	return dp[x][y];
}
int main() {
	int k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}
	while (k--) {
		int a, b;
		LL c;
		scanf("%d %d %lld", &a, &b, &c);
		sex[a-1][b-1] = c;
	}
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}
	printf("%lld\n", serc(0, 0));
	return 0;
}
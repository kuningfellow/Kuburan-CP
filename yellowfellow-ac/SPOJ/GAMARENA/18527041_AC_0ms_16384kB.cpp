#include<stdio.h>

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, k, L, W;
		scanf("%d %d %d %d", &n, &k, &L, &W);
		int ans = ~(1 << 31);
		for (int i = 0; ; i++) {
			int hub = i * k;
			int rem = n - hub;
			if (rem > i * k - 2 * (i - 1)) continue;
			if (rem < 0) rem = 0;
			ans = min(ans, i * W + (i - 1) * L + rem * L);
			if (rem == 0) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
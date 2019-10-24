#include<bits/stdc++.h>
using namespace std;
int dp[501][501];
int B[501];
int W[501];
void serc(int k, int l, int r, int optl, int optr) {
	if (l > r) return;
	int opt = optl;
	int mid = (l + r) / 2;
	int R = min(R, optr);
	for (int i = 1; i <= mid; i++) {
		
		if (dp[k-1][i-1] + (B[mid]-B[i-1]) * (W[mid]-W[i-1]) < dp[k][mid]) {
			dp[k][mid] = dp[k-1][i-1] + (B[mid]-B[i-1]) * (W[mid]-W[i-1]);
			opt = i;
		}
	}
	serc(k, l, mid - 1, optl, opt);
	serc(k, mid + 1, r, opt, optr);
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		if (a == 0) W[i] = 1;
		else B[i] = 1;
		W[i] += W[i-1];
		B[i] += B[i-1];
	}
	for (int i = 0; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = (-1) ^ (1 << 31);
		}
	}
	for (int i = 0; i <= n; i++) {
		dp[0][i] = W[i] * B[i];
	}
	for (int i = 1; i < k; i++) {
		serc(i, 1, n, 1, n);
	}
	printf("%d\n", dp[k-1][n]);
}
#include<stdio.h>

typedef long long int LL;

LL ar[2005];
LL pref[2005];
LL spref[2005];
LL dp[2005][2005];
int K;

int min(int a, int b) {
	return a < b ? a : b;
}

LL cost(int l, int r) {
	LL ret = 0;
	if (K == 1) {
		int mid = (l + r) / 2;
		return ar[mid] * (2*mid - l - r + 1) - 2*pref[mid] + pref[l-1] + pref[r];
	}
	else {
		LL mid = ((double) pref[r] - pref[l - 1]) / (r - l + 1);
		LL A = mid * mid * (r-l+1) - 2*mid++*(pref[r] - pref[l - 1]);
		LL B = mid * mid * (r-l+1) - 2*mid  *(pref[r] - pref[l - 1]);
		if (B < A) A = B;
		return A + spref[r] - spref[l - 1];
	}
}

void serc(int k, int l, int r, int optl, int optr) {
	if (l > r) return;
	int mid = (l + r) / 2;
	int L = min(optl, mid);
	int R = min(optr, mid);
	int opt = mid;
	dp[k][mid] = (1ll << 62);
	for (int i = L; i <= R; i++) {
		double tmp = dp[k - 1][i - 1] + cost(i, mid);
		if (tmp < dp[k][mid]) {
			dp[k][mid] = tmp;
			opt = i;
		}
	}
	serc(k, l, mid - 1, optl, opt);
	serc(k, mid + 1, r, opt, optr);
}

int main() {
	int n, g;
	scanf("%d %d %d", &n, &g, &K);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &ar[i]);
		pref[i] = pref[i - 1] + ar[i];
		spref[i] = spref[i - 1] + ar[i] * ar[i];
	}
	for (int i = 1; i <= n; i++) dp[0][i] = cost(1, i);
	for (int i = 1; i < g; i++) serc(i, 1, n, 1, n);
	printf("%lld\n", dp[g - 1][n]);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define fto(i, l, r) for(int i = l; i <= r; ++i)
LL M;
int n;
LL dp[1000005][2];
LL fexpo(LL base, int p) {
    LL ret = 1;
    while (p > 0) {
        if (p % 2 == 1) ret = ret * base % M;
        base = base * base % M;
        p /= 2;
    }
    return ret;
}
LL num[1000005];
LL den[1000005];
int gcd(int a, int b) {
	int ret = 1;
	while (ret) {
		ret = a % b;
		a = b;
		b = ret;
	}
	return a;
}
int p[1000005];
LL comb(int a, int b) {
	for (int i = 1; i <= a; i++) {
		num[i] = i;
		den[i] = i;
	}
	for (int i = 2; i <= b; i++) {
		int sta = (a-b)/i*i;
		if ((a-b)%i) sta += i;
		for (int j = sta; j <= a && den[i] > 1; j += i) {
			int g = gcd(den[i], num[j]);
			while (g > 1) {
				den[i] /= g;
				num[j] /= g;
				g = gcd(den[i], num[j]);
			}
		}
	}
	LL ret = 1;
	for (int i = a-b; i <= a; i++) {
		ret = ret * num[i] % M;
	}
	return ret;
}
void upd(vector<int> &cnt, int n, int sign) {
    while (n > 1) {
        cnt[p[n]] += sign;
        n /= p[n];
    }
}
int C(int n, int k) {
    vector<int> p(n+1, 0);
    fto(i, k+1, n) upd(p, i, 1);
    fto(i, 1, n-k) upd(p, i, -1);
    int res = 1%M;
    fto(i, 1, n) {
        fto(x, 1, p[i]) res = (1LL*res*i)%M;
    }
    return res;
}
int main() {
	p[1] = 1;
	for(int i = 2; i < 1000005; ++i) {
        for(int j = i; j < 1000005; j += i) {
            if (!p[j]) p[j] = i;
        }
    }
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %lld", &n, &M);
		for (int i = 0; i < n; i++) {
			dp[i][0] = dp[i][1] = -1;
		}
		dp[n][0] = 1;
		dp[n][1] = 1;
		for (int i = n-1; i >= 0; i--) {
			dp[i][0] = dp[i+1][1];
			dp[i][1] = (dp[i+1][0] + dp[i+1][1]) % M;
		}
		LL ans = (dp[1][0] + dp[1][1]) % M;
		if (n % 2 == 0) {
			LL tmp = C(n, n/2);
		    ans = ((ans + tmp - (n/2 + 1) % M + M) % M + M) % M;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

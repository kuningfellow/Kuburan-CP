#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL M;
int n;
LL dp[1000005][2];
bool isprime[1000005];
vector<int>lis;
void sieve() {
	for (int i = 2; i < 1000005; i++) {
		if (isprime[i] == 0) {
			lis.push_back(i);
			for (int j = i * 2; j < 1000005; j+=i) {
				isprime[j] = 1;
			}
		}
	}
}
int cnt[100000];
int cnt2[100000];
LL fexpo(LL base, int p) {
	LL ret = 1;
	while (p) {
		if (p % 2) ret = ret * base % M;
		base = base * base % M;
		p /= 2;
	}
	return ret;
}
LL comb(int a) {
	int b = a / 2;
	for (int i = 0; i < 100000; i++) {
		cnt[i] = cnt2[i] = 0;
	}
	for (int i = 0; i < lis.size(); i++) {
		int sta = (b + 1) / lis[i] * lis[i];
		if ((b + 1) % lis[i]) sta += lis[i];
		for (int j = sta; j <= a; j += lis[i]) {
			int eval = j;
			while (eval % lis[i] == 0) {
				eval /= lis[i];
				cnt[i]++;
			}
		}
	}
	for (int i = 0; i < lis.size(); i++) {
		for (int j = lis[i]; j <= b; j += lis[i]) {
			int eval = j;
			while (eval % lis[i] == 0) {
				eval /= lis[i];
				cnt2[i]++;
			}
		}
	}
	LL res = 1;
	for (int i = 0; i < lis.size(); i++) {
		res = res * fexpo(lis[i], cnt[i] - cnt2[i]) % M;
	}
	return res;
}
int main() {
	sieve();
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
			LL tmp = comb(n);
		    ans = ((ans + tmp - (n/2 + 1) % M + M) % M + M) % M;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

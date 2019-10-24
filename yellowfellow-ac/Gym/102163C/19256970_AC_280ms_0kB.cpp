#include<stdio.h>

typedef long long int LL;

const LL mod = 1000000007;

int lis[1005];
int franxx[1005];
LL darling[1005];

LL max(LL a, LL b) {
	if (a > b) return a;
	return b;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		
		lis[n] = mod;
		franxx[n] = 0;
		darling[n] = 1;
		for (int i = 0; i < n; i++) {
			scanf("%d", &lis[i]);
			franxx[i] = darling[i] = 0;
		}
		
		LL zero_two = 0, ans = 0;
		for (int i = n-1; i >= 0; i--) {
			for (int j = i + 1; j <= n; j++) {
				if (lis[i] < lis[j]) franxx[i] = max(franxx[i], franxx[j] + 1);
			}
			for (int j = i + 1; j <= n; j++) {
				if (lis[i] < lis[j] && franxx[i] == franxx[j] + 1)
					darling[i] = (darling[i] + darling[j]) % mod;
			}
			zero_two = max(zero_two, franxx[i]);
		}
			
		for (int i = 0; i < n; i++) {
			if (franxx[i] == zero_two) ans = (ans + darling[i]) % mod;
		}
	
		printf("%lld %lld\n", zero_two, ans);
	}
	return 0;
}
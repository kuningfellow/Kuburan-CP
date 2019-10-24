#include<stdio.h>
#define TC int TC;scanf("%d",&TC);while(TC--)

typedef long long int LL;

const LL MOD = 1000000007;

LL fac[100005];
LL ifac[100005];
LL fexpo(LL b, int p) {
	LL ret = 1;
	while (p) {
		if (p % 2) ret = ret * b % MOD;
		b = b * b % MOD;
		p /= 2;
	}
	return ret;
}
LL comb(int a, int b) {
	return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

int main() {
	fac[0] = 1;
	ifac[0] = 1;
	for (int i = 1; i < 100005; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		ifac[i] = fexpo(fac[i], MOD - 2);
	}
	TC {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld\n", 2 * comb(a - 1, b) % MOD);
	}
	return 0;
}
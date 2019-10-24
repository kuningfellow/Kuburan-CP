#include<stdio.h>

typedef long long int LL;
const LL MOD = 1000000007;

int main() {
	LL n;
	scanf("%lld", &n);
	if (n == 0) {
		printf("1\n");
		return 0;
	}
	LL A = 1, B = 1;
	LL base = 4;
	n--;
	LL tmp = n;
	while (tmp) {
		if (tmp % 2) A = A * base % MOD;
		base = base * base % MOD;
		tmp /= 2;
	}
	base = 2;
	tmp = n;
	while (tmp) {
		if (tmp % 2) B = B * base % MOD;
		base = base * base % MOD;
		tmp /= 2;
	}
	printf("%lld\n", (A * 2 + B) % MOD);
	return 0;
}
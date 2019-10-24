//UVA 10706 Number Sequence
#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int dig(int n) {
	int ret = 0;
	while (n > 0) {
		ret++;
		n /= 10;
	}
	return ret;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		LL n;
		scanf("%lld", &n);
		LL red = 1;
		LL car = 1;
		while (n > red) {
			car++;
			n -= red;
			red += dig(car);
		}
		red = 9;
		car = 1;
		LL len = 1;
		while (n > red) {
			n -= red;
			car *= 10;
			len++;
			red = len * 9 * car;
		}
		n--;
		LL tmp = n / len + car;
		LL ans;
		int p = n % len;
		p = len - p - 1;
		for (int i = 0; i < p; i++) {
			tmp /= 10;
		}
		ans = tmp % 10;
		printf("%lld\n", ans);
	}
}
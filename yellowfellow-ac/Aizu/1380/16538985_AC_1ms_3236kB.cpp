#include<bits/stdc++.h>
typedef long long int LL;
using namespace std;
int main() {
	int n;
	LL t;
	scanf("%d%lld", &n, &t);
	LL delta = 0;
	LL prev = 0;
	LL prev2 = 0;
	LL pans = 0;
	LL gap;
	for (int i = 0; i < n; i++) {
		LL a;
		scanf("%lld", &a);
		if (a > delta) {
			pans = (t-prev)/a;
			printf("%lld\n", 1 + max(0ll, pans));
			delta = a;
			prev2 = prev + (t-prev)/a*a + a;
		}
		else {
			gap = 0;
			if (prev2 + a > (t+0.5)) {
				gap = prev2+a - (t+0.5);
				gap = gap/delta;
				prev2 = prev2 - delta*gap + a;
			}
			pans = pans - gap;
			printf("%lld\n", 1 + max(0ll, pans));
		}
		prev += a;
	}
}
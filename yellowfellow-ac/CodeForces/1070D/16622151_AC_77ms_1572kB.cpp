#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL ar[200005];
int main() {
	int n;
	LL k;
	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &ar[i]);
	}
	LL tmp = k;
	LL ans = 1;
	int prev = 0;
	for (int i = 0; i < n; i++) {
		LL red = min(tmp, ar[i]);
		tmp -= red;
		ar[i] -= red;
		if (prev > 0 || tmp == 0) {
			ans++;
			tmp = k;
			red = 0;
			prev = 0;
		}
		ans += ar[i]/k;
		tmp -= ar[i]%k;
		if (ar[i]%k > 0 || red > 0) prev = 1;
	}
	if (tmp == k) ans--;
	printf("%lld\n", ans);
}
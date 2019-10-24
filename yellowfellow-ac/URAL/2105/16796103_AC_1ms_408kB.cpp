#include<bits/stdc++.h>
using namespace std;
int main() {
	int L, T, vA, vB;
	scanf("%d %d %d %d", &L, &T, &vA, &vB);
	int dA = vA * T;
	int dB = vB * T;
	int n;
	scanf("%d", &n);
	while (n--) {
		int type, t, d;
		scanf("%d %d %d", &type, &t, &d);
		if (type == 1) dA -= vA * d;
		else dB -= vB * d;
	}
	int ans = dA/L + dB/L;
	dA %= L;
	dB %= L;
	if (dA > L - dB) ans++;
	printf("%d\n", ans);
}
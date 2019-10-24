#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL MOD = 1000000007;
LL ans[1000005];
int ar[8] = {3, 6, 9, 12, 15, 18, 21, 24};
int main(){
	ans[0] = 1;
	for (int i = 0; i < 1000005; i++) {
		for (int j = 0; j < 8; j++) {
			if (i - ar[j] >= 0){
				ans[i] = (ans[i] + ans[i - ar[j]]) % MOD;
			}
		}
	}
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}
}
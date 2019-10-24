//UVA 1240 ICPC Team Strategy
#include<bits/stdc++.h>
using namespace std;
int dp[(1<<12)][285][3];
int ar[13][3];
int n;
int serc(int mask, int t, int l){
	if (dp[mask][t][l] != -1){
		return dp[mask][t][l];
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if ((mask&(1<<i)) == 0){
			for (int j = 0; j < 3; j++){
				if (j == l && mask != 0) continue;
				if (t - ar[i][j] >= 0){
					ret = max(ret, 1 + serc(mask|(1<<i), t - ar[i][j], j));
				}
			}
		}
	}
	return dp[mask][t][l] = ret;
}
int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &ar[i][0]);
		for (int i = 0; i < n; i++) scanf("%d", &ar[i][1]);
		for (int i = 0; i < n; i++) scanf("%d", &ar[i][2]);
		for (int i = 0; i < (1<<n); i++) {
			for (int j = 0; j < 285; j++) {
				for (int k = 0; k < 3; k++) {
					dp[i][j][k] = -1;
				}
			}
		}
		printf("%d\n", serc(0, 280, 0));
	}
}
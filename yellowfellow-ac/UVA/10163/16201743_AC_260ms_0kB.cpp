//UVA 10163 Storage Keepers
#include<bits/stdc++.h>
using namespace std;
int dp[105][35][1005];
int ar[35];
int n, m;
int serc(int x, int p, int mini){
	if (x == 0) {
		return 0;
	}
	if (p == m) {
		return mini == 0 ? 0 : 1000000;
	}
	if (dp[x][p][mini] != -1) {
		return dp[x][p][mini];
	}
	dp[x][p][mini] = 1000000;
	dp[x][p][mini] = serc(x, p + 1, mini);
	int ret;
	for (int i = 1; i <= x; i++) {
		if (ar[p] / i < mini) continue;
		ret = serc(x - i, p + 1, mini);
		ret += ar[p];
		dp[x][p][mini] = min(dp[x][p][mini], ret);
	}
	return dp[x][p][mini];
}
int main(){
	while (1 < 2) {
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;
		for (int i = 0; i < m; i++) {
			scanf("%d", &ar[i]);
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 1005; k++) {
					dp[i][j][k] = -1;
				}
			}
		}
		for (int i = 1000; i >= 0; i--) {
			int res = serc(n, 0, i);
			if (res != 1000000) {
				printf("%d %d\n", i, res);
				break;
			}
		}
	}
}

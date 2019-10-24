//UVA 882 The Mailbox Manufacturers Problem
#include<bits/stdc++.h>
using namespace std;
int dp[11][101][101];
int serc(int k, int m, int s){
	if (m == 0) return 0;
	if (k == 1) return ( m * ( s*2 + (m-1) ) ) / 2;
	if (dp[k][m][s] != -1) return dp[k][m][s];
	dp[k][m][s] = (-1) ^ (1 << 31);
	for (int i = 0; i < m; i++) {
		dp[k][m][s] = min(dp[k][m][s], s + i + max( serc(k - 1, i, s), serc(k, m - i - 1, s + i + 1) ) );
	}
	return dp[k][m][s];
}
int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int k, m;
		scanf("%d%d", &k, &m);
		for (int i = 0; i <= k; i++) {
			for (int j = 0; j <= m; j++) {
				for (int k = 0; k <= m; k++) {
					dp[i][j][k] = -1;
				}
			}
		}
		printf("%d\n", serc(k, m, 1));
	}
}
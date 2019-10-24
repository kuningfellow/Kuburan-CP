//UVA 12324 Philip J. Fry Problem
#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int ar[105];
int br[105];
int n;
int serc(int x, int r){
	r = min(r, n);
	if (x == n) return 0;
	if (dp[x][r] != -1) return dp[x][r];
	return dp[x][r] = min(ar[x] + serc(x+1, r+br[x]), r>0 ? ar[x]/2 + serc(x+1, r-1+br[x]) : (-1)^(1 << 31));
}
int main(){
	while (1 < 2) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &ar[i], &br[i]);
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j] = -1;
			}
		}
		printf("%d\n", serc(0, 0));
	}
}
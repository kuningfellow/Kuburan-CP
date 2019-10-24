//SPOJ MIXTURES
//Matrix Chain Multiplication
#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int ar[105];
int serc(int l, int r){
	if (l == r){
		return 0;
	}
	if (dp[l][r] != -1){
		return dp[l][r];
	}
	int ret = (-1) ^ (1 << 31);
	for (int i = l; i < r; i++) {
		ret = min(ret, ((ar[i]-ar[l-1])%100) * ((ar[r]-ar[i])%100) + serc(l, i) + serc(i + 1, r) );
	}
	return dp[l][r] = ret;
}
int main(){
	int n;
	while (scanf("%d", &n) != EOF){
		for (int i = 1; i <= n; i++) {
			scanf("%d", &ar[i]);
		}
		ar[0] = 0;
		for (int i = 1; i <= n; i++) {
			ar[i] += ar[i-1];
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j] = -1;
			}
		}
		printf("%d\n", serc(1, n));
	}
}
//UVA 10482 The Candyman Can
#include<bits/stdc++.h>
using namespace std;
int dp[32][41][41][41];
int ar[32];
int n;
int trimin(int a, int b, int c){
	return min(a, min(b, c));
}
int serc(int x, int a, int b, int c){
	if (a > 40 || b > 40 || c > 40) {
		return (-1) ^ (1 << 31);
	}
	int red = trimin(a, b, c);
	a -= red;
	b -= red;
	c -= red;
	if (x == n) {
		return max(a, max(b, c)) - trimin(a, b, c);
	}
	if (dp[x][a][b][c] != -1) {
		return dp[x][a][b][c];
	}
	return dp[x][a][b][c] = trimin(serc(x+1, a+ar[x], b, c), serc(x+1, a, b+ar[x], c), serc(x+1, a, b, c+ar[x]));
}
int main(){
	int kas = 1;
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &ar[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 41; j++) {
				for (int k = 0; k < 41; k++) {
					for (int l = 0; l < 41; l++) {
						dp[i][j][k][l] = -1;
					}
				}
			}
		}
		printf("Case %d: %d\n", kas++, serc(0, 0, 0, 0));
	}
}
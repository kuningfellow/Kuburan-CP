//UVA 10304 Optimal Binary Search Tree
//Knuth's Optimization
#include<bits/stdc++.h>
using namespace std;
int dp[255][255];
int ar[255];
int pref[255];
int mid[255][255];
int main(){
	int n;
	while (scanf("%d", &n) != EOF){
		for (int i = 0; i < n; i++) {
			scanf("%d", &ar[i]);
		}
		int car = 0;
		for (int i = 0; i <= n; i++) {
			pref[i] = car;
			car += ar[i];
		}
		for (int s = 0; s <= n; s++) {
			for (int l = 0; l+s <= n; l++) {
				int r = l + s;
				if (s < 2){
					dp[l][r] = 0;
					mid[l][r] = l;
				}
				else {
					int left = mid[l][r - 1];
					int right = mid[l + 1][r];
					dp[l][r] = (-1)^(1<<31);
					for (int k = left; k <= right; k++) {
						int ret = ( dp[l][k] + dp[k+1][r] ) + ( pref[r] - pref[l] - ar[k] );
						if (ret < dp[l][r]){
							dp[l][r] = ret;
							mid[l][r] = k;
						}
					}
				}
			}
		}
		printf("%d\n", dp[0][n]);
	}
}
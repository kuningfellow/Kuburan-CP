//UVA 11218 KTV
#include<bits/stdc++.h>
using namespace std;
int ar[80][2];
int dp[80][(1 << 9)];
int n;
int serc(int x, int mask){
	if (x == n) return (mask == (1 << 9) - 1) ? 0 : (1 << 31);
	if (dp[x][mask] != -1) return dp[x][mask];
	return dp[x][mask] = max(serc(x+1, mask), (ar[x][0]&mask) == 0 ? (ar[x][1] + serc(x+1, mask|ar[x][0])) : (1<<31) );
}
void read(int i){
	int a;
	int mask = 0;
	for (int j = 0; j < 3; j++) {
		scanf("%d", &a);
		mask |= (1 << (a-1));
	}
	scanf("%d", &a);
	ar[i][0] = mask;
	ar[i][1] = a;
}
void reset(){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1<<9); j++) {
			dp[i][j] = -1;
		}
	}
}
int main(){
	int kas = 1;
	while (1 < 2){
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++) read(i);
		reset();
		int ans = serc(0, 0);
		ans = ans < 0 ? -1 : ans;
		printf("Case %d: %d\n", kas++, ans);
	}
}
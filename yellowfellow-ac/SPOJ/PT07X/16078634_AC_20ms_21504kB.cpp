#include<bits/stdc++.h>
using namespace std;
int dp[100005][2];
vector<int> lis[100005];
int par[100005];
int makepar(int x, int p){
	par[x] = p;
	for (int i = 0; i < lis[x].size(); i++) {
		if (lis[x][i] != p) {
			makepar(lis[x][i], x);
		}
	}
}
int serc(int x, int mode){
	if (dp[x][mode] != -1){
		return dp[x][mode];
	}
	int ret = 0;
	for (int i = 0; i < lis[x].size(); i++) {
		if (lis[x][i] != par[x]) {
			if (mode == 1) {
				ret += min(serc(lis[x][i], 0), 1 + serc(lis[x][i], 1));
			}
			else {
				ret += 1 + serc(lis[x][i], 1);
			}
		}
	}
	return dp[x][mode] = ret;
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		dp[i][0] = dp[i][1] = -1;
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	makepar(1, 1);
	int ans = min(serc(1, 0), 1 + serc(1, 1));
	printf("%d\n", ans);
}
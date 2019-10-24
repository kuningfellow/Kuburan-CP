#include<bits/stdc++.h>
using namespace std;
vector<int>lis[200005];
int weight[200005];
int vis[200005];
int k;
int dfs(int x){
	vis[x] = 1;
	weight[x] = 1;
	for (int i = 0; i < lis[x].size(); i++) {
		if (vis[lis[x][i]] == 0){
			weight[x] += dfs(lis[x][i]);
		}
	}
	return weight[x];
}
int ans;
void dfs2(int x, int p){
	vis[x] = 1;
	if (weight[x] >= k && p >= k){
		ans++;
	}
	for (int i = 0; i < lis[x].size(); i++) {
		if (vis[lis[x][i]] == 0){
			dfs2(lis[x][i], p + weight[x] - weight[lis[x][i]]);
		}
	}
}
int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		ans = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) {
			lis[i].clear();
			weight[i] = 0;
			vis[i] = 0;
		}
		for (int i = 1; i < n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			lis[a].push_back(b);
			lis[b].push_back(a);
		}
		dfs(1);
		for (int i = 1; i <= n; i++) {
			vis[i] = 0;
		}
		dfs2(1, 0);
		printf("%d\n", ans);
	}
}
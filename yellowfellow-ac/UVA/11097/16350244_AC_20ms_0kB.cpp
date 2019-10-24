//UVA 11097 Poor My Problem! :-(
#include<bits/stdc++.h>
using namespace std;
double dp[600][1001];
vector<pair<int,int> > lis[600];
void serc(int x, int d) {
	if (dp[x][d] == ((-1) ^ (1 << 31))) return;
	for (int i = 0; i < lis[x].size(); i++) {
		dp[lis[x][i].first][d+1] = min(dp[lis[x][i].first][d+1], dp[x][d] + lis[x][i].second);
	}
	return;
}
int main() {
	int v, e, s;
	while (scanf("%d%d%d", &v, &e, &s) != EOF) {
		for (int i = 0; i < 600; i++) {
			lis[i].clear();
			for (int j = 0; j < 1001; j++) {
				dp[i][j] = (-1) ^ (1 << 31);
			}
		}
		for (int i = 0; i < e; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			lis[a].push_back(pair<int,int>(b, c));
		}
		dp[s][0] = 0;
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < v; j++) {
				serc(j, i);
			}
		}
		int q;
		scanf("%d", &q);
		while (q--) {
			int a;
			scanf("%d", &a);
			if (a == s) {
				printf("%.4f %d\n", 0.0, 0);
				continue;
			}
			double best = (-1) ^ (1 << 31);
			int ans = -1;
			for (int i = 1; i < 1001; i++) {
				if (dp[a][i] != ((-1) ^ (1 << 31))){
					if (best > dp[a][i] / i) {
						best = dp[a][i] / i;
						ans = i;
					}
				}
			}
			if (ans == -1) printf("No Path\n");
			else printf("%.4f %d\n", best, ans);
		}
		printf("\n");
	}
}
#include<bits/stdc++.h>
using namespace std;
pair<int,int> dp[(1<<14)][305];
int ar[14];
int n, p;
pair<int,int> serc(int x, int t) {
	if (dp[x][t].first != -1) {
		return dp[x][t];
	}
	dp[x][t].first = 0;
	dp[x][t].second = 0;
	pair<int,int> ret;
	if (x == 0) {
		if (t >= ar[p]) {
			ret = serc((1 << p), t - ar[p]);
			ret.first++;
			ret.second += ar[p] * ret.first;
			dp[x][t] = ret;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if ((x & (1 << i)) == 0 && t >= ar[i]) {
				ret = serc(x|(1 << i), t - ar[i]);
				ret.first++;
				ret.second += ar[i] * ret.first;
				if (ret.first > dp[x][t].first || (ret.first == dp[x][t].first && ret.second < dp[x][t].second)) {
					dp[x][t] = ret;
				}
			}
		}
	}
	return dp[x][t];
}
int main() {
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}
	for (int i = 0; i < (1<<n); i++) {
		for (int j = 0; j < 305; j++) {
			dp[i][j].first = -1;
		}
	}
	pair<int,int> ans = serc(0, 300);
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}
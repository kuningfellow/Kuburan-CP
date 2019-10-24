#include<bits/stdc++.h>
using namespace std;
pair<int,int> pts[16];
map<pair<int,int>, int>cnt;
int check(int a, int b, int c, int d) {
	int v1 = pts[a].first - pts[b].first;
	int v2 = pts[a].second - pts[b].second;
	int u1 = pts[c].first - pts[d].first;
	int u2 = pts[c].second - pts[d].second;
	int cross = v1 * u2 - u1 * v2;
	if (cross == 0) {
		return 1;
	}
	return 0;
}
int m;
vector<int> conf[256];
int dp[(1<<16)];
int serc(int mask) {
	if (dp[mask] != -1) return dp[mask];
	int ret = 0;
	int cnt = 0;
	int misk;
	for (int j = 0; j < m*m; j++) {
		misk = mask;
		cnt = 0;
		for (int i = 0; i < conf[j].size(); i++) {
			if ((misk & conf[j][i]) == 0) {
				cnt++;
				misk|=conf[j][i];
			}
		}
if(cnt)ret = max(ret, cnt*(cnt-1)/2 + serc(misk));
	}
	return dp[mask] = ret;
}
int main(){
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &pts[i].first, &pts[i].second);
	}
	for (int i = 0; i < m; i++) {
		for (int j = i+1; j < m; j++) {
			conf[i*m + j].push_back((1<<i) | (1<<j));
			for (int k = 0; k < m; k++) {
				if (k == i || k == j) continue;
				for (int l = k+1; l < m; l++) {
					if (l == i || l == j) continue;
					if (check(i, j, k, l)) {
						conf[i*m + j].push_back((1<<k) | (1<<l));
					}
				}
			}
		}
	}
	// for (int i = 0; i < m; i++) {
		for (int j = 0; j < (1<<m); j++) {
			dp[j] = -1;
		}
	// }
	printf("%d\n", serc(0));
}
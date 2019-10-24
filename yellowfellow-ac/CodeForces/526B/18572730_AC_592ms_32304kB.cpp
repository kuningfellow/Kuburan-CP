#include<stdio.h>
#include<vector>

using namespace std;

vector<pair<int,int> >lis[(1 << 12)];
int size[1 << 13];
int dp[1 << 13][1005];

int req(int x) {
	int ret = 0;
	for (int i = 0; i < lis[x].size(); i++) {
		ret = max(ret, lis[x][i].second + req(lis[x][i].first));
	}
	size[x] = ret;
	return ret;
}

int serc(int x, int rec) {
	if (rec < 0) return 1000000;
	if (lis[x].size() == 0) {
		return rec;
	}
	if (dp[x][rec] != -1) return dp[x][rec];
	dp[x][rec] = 1000000;	
	for (int i = 0; i <= rec; i++) {
		dp[x][rec] = min(dp[x][rec], 
			i + serc(lis[x][0].first, rec - i - lis[x][0].second)
			+ serc(lis[x][1].first, rec - i - lis[x][1].second));
		if (x == 1) break;
	}
	return dp[x][rec];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i < (1 << n + 1); i++) {
		int x;
		scanf("%d", &x);
		lis[i / 2].push_back(pair<int,int>(i, x));
	}
	int mini = req(1);
	for (int i = 1; i <= (1 << n + 1); i++) {
		for (int j = 0; j <= mini; j++) {
			dp[i][j] = -1;
		}
	}
	int ans = serc(1, mini);
	printf("%d\n", ans);
}
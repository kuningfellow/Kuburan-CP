#include<stdio.h>
#include<queue>

using namespace std;

deque<pair<int,int> > dqr[2005];
deque<pair<int,int> > dql[2005];
int dp[2005][2005];
int mid[2005][2005];
int ar[2005];
int n;

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int min(int a, int b) {
	return -max(-a, -b);
}

int serc(int l, int r) {
	if (l > r) return 0;
	if (dp[l][r] != -1) return dp[l][r];
	
	serc(l+1, r);
	serc(l, r-1);
	
	if (l == r) {
		dp[l][r] = ar[l];
		int ins, idx;
		if (l - 1 >= 0) {
			ins = dp[l][l] + ar[l - 1];
			idx = l - 1;
			dql[r].push_back(pair<int,int>(ins, idx));
		}
		if (r + 1 < n) {
			ins = dp[l][l] + ar[r + 1];
			idx = r + 1;
			dqr[l].push_front(pair<int,int>(ins, idx));
		}
		mid[l][r] = l;
		return dp[l][r];
	}
	else {
		int bord = mid[l][r - 1];
		for (int i = mid[l][r - 1]; i <= mid[l + 1][r]; i++) {
			bord = i;
			if (dp[l][i - 1] > dp[i + 1][r]) break;
		}
		mid[l][r] = bord;
		dp[l][r] = ~(1 << 31);
		
		while (!dql[r].empty() && dql[r].front().second >= bord) dql[r].pop_front();
		if (!dql[r].empty()) dp[l][r] = min(dp[l][r], dql[r].front().first);
		
		while (!dqr[l].empty() && dqr[l].back().second < bord) dqr[l].pop_back();
		if (!dqr[l].empty()) dp[l][r] = min(dp[l][r], dqr[l].back().first);
		
		int ins, idx;
		if (l - 1 >= 0) {
			ins = dp[l][r] + ar[l - 1];
			idx = l - 1;
			while (!dql[r].empty() && dql[r].back().first >= ins) dql[r].pop_back();
			dql[r].push_back(pair<int,int>(ins, idx));
		}
		if (r + 1 < n) {
			ins = dp[l][r] + ar[r + 1];
			idx = r + 1;
			while (!dqr[l].empty() && dqr[l].front().first >= ins) dqr[l].pop_front();
			dqr[l].push_front(pair<int,int>(ins, idx));
		}
		return dp[l][r];
	}
	
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}
	printf("%d\n", serc(0, n-1));
	return 0;
}
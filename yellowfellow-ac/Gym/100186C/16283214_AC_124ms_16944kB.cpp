#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
pair<pair<int,int>,int>	bt[1005][1005];
char mark[1005][1005];
int n, m;
int serc(int x, int y) {
	if (x == n - 1 && y == m - 1) return 0;
	if (dp[x][y] != -1) return dp[x][y];
	int eval;
	dp[x][y] = 1000000;
	if (mark[x][y] == '.') {
		if (x + 1 < n) {
			eval = serc(x + 1, y);
			if (eval < dp[x][y]) {
				dp[x][y] = eval;
				bt[x][y].first.first = x + 1;
				bt[x][y].first.second = y;
				bt[x][y].second = 0;
			}
		}
		if (y + 1 < m) {
			eval = serc(x, y + 1);
			if (eval < dp[x][y]) {
				dp[x][y] = eval;
				bt[x][y].first.first = x;
				bt[x][y].first.second = y + 1;
				bt[x][y].second = 0;
			}
		}
	}
	else {
		int r = m;
		int b = n;
		for (int i = y; i < m; i++) {
			if (mark[x][i] != mark[x][y]) {
				r = i;
				break;
			}
		}
		for (int i = x; i < n; i++) {
			if (mark[i][y] != mark[x][y]) {
				b = i;
				break;
			}
		}
		if (r != m) {
			for (int i = x; i < b; i++) {
				eval = max(r + i - x - y, serc(i, r));
				if (eval < dp[x][y]) {
					dp[x][y] = eval;
					bt[x][y].first.first = i;
					bt[x][y].first.second = r;
					bt[x][y].second = 1;
				}
			}
		}
		if (b != n) {
			for (int i = y; i < r; i++){
				eval = max(b + i - x - y, serc(b, i));
				if (eval < dp[x][y]) {
					dp[x][y] = eval;
					bt[x][y].first.first = b;
					bt[x][y].first.second = i;
					bt[x][y].second = 2;
				}
			}
		}
	}
	return dp[x][y];
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", mark[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = -1;
		}
	}
	printf("%d\n", serc(0, 0));
	int x = 0, y = 0;
	printf("1 1\n");
	while (1 < 2) {
		int tx = bt[x][y].first.first;
		int ty = bt[x][y].first.second;
		if (bt[x][y].second == 0) {
			x = tx;
			y = ty;
			printf("%d %d\n", x + 1, y + 1);
		}
		else if (bt[x][y].second == 1) {
			while (x < tx) {
				x++;
				printf("%d %d\n", x + 1, y + 1);
			}
			while (y < ty) {
				y++;
				printf("%d %d\n", x + 1, y + 1);
			}
		}
		else if (bt[x][y].second == 2) {
			while (y < ty) {
				y++;
				printf("%d %d\n", x + 1, y + 1);
			}
			while (x < tx) {
				x++;
				printf("%d %d\n", x + 1, y + 1);
			}
		}
		if (x == n - 1 && y == m - 1) break;
	}
}
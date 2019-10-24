#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
char str[2005];
char str2[2005];
int l1, l2;
int serc(int x, int y) {
	if (y == l2) return abs(x - l1);
	if (x == l1) return abs(l2 - y);
	if (dp[x][y] != -1) return dp[x][y];
	int& ret = dp[x][y];
	ret = (-1) ^ (1 << 31);
	if (str[x] == str2[y]) ret = min(ret, serc(x + 1, y + 1));
	else dp[x][y] = min(ret, 1 + serc(x + 1, y + 1));
	ret = min(ret, 1 + serc(x + 1, y));
	ret = min(ret, 1 + serc(x, y + 1));
	return ret;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", str);
		scanf("%s", str2);
		l1 = strlen(str);
		l2 = strlen(str2);
		for (int i = 0; i < l1; i++) {
			for (int j = 0; j < l2; j++) {
				dp[i][j] = -1;
			}
		}
		printf("%d\n", serc(0, 0));
	}
}
#include<stdio.h>

int dp[11][11][11][11];

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int serc(int x, int a, int b, int c) {
	if (x == -1) {
		if (a || b || c) return -100000000;
		else return 0;
	}
	if (dp[x][a][b][c] != -1) return dp[x][a][b][c];
	dp[x][a][b][c] = -100000000;
	for (int i = a > 0; i >= 0; i--) {
		for (int j = b > 0; j >= 0; j--) {
			for (int k = c > 0; k >= 0; k--) {
				dp[x][a][b][c] = max(dp[x][a][b][c], ((i^j^k) << x) + serc(x-1, a-i, b-j, c-k));
			}
		}
	}
	return dp[x][a][b][c];
}

void print(int x, int a) {
	if (a == 0) return;
	int r = x & 1;
	print(x / 2, a - 1);
	printf("%d", r);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		char tmp[50];
		int ar[3] = {0, 0, 0};
		for (int i = 0; i < 3; i++) {
			scanf("%s", tmp);
			for (int j = 0; j < 10; j++) {
				if (tmp[j] == '1') ar[i]++;
			}
		}
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				for (int k = 0; k < 11; k++) {
					for (int l = 0; l < 11; l++) {
						dp[i][j][k][l] = -1;
					}
				}
			}
		}
		int ans = serc(9, ar[0], ar[1], ar[2]);
		print(ans, 10);
		printf("\n");
	}
	return 0;
}
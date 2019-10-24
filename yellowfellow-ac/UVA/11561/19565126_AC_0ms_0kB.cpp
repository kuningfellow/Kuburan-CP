#include<stdio.h>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char grid[55][55];
int vis[55][55];
int W, H;
int serc(int x, int y) {
	int ret = 0;
	vis[x][y] = 1;
	int stop = 0;
	if (grid[x][y] == 'G') ret++;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] >= 0 && x + dx[i] < H && y + dy[i] >= 0 && y + dy[i] < W && vis[x + dx[i]][y + dy[i]] == 0 && grid[x + dx[i]][y + dy[i]] == 'T') {
			stop = 1;
		}
	}
	if (stop) return ret;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] >= 0 && x + dx[i] < H && y + dy[i] >= 0 && y + dy[i] < W && vis[x + dx[i]][y + dy[i]] == 0 && (grid[x + dx[i]][y + dy[i]] == 'G' || grid[x + dx[i]][y + dy[i]] == '.')) {
			ret += serc(x + dx[i], y + dy[i]);
		}
	}
	return ret;
}

int main() {
	while (scanf("%d %d", &W, &H) != EOF) {
		int x, y;
		for (int i = 0; i < H; i++) {
			scanf("%s", grid[i]);
			for (int j = 0; j < W; j++) {
				vis[i][j] = 0;
				if (grid[i][j] == 'P') x = i, y = j;
			}
		}
		printf("%d\n", serc(x, y));
	}
	return 0;
}
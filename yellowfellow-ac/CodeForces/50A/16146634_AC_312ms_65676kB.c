#include<stdio.h>

int dp[16][16][(1 << 16)];
int n, m;

int max(int a, int b){
	if (a > b) return a;
	return b;
}

int serc(int x, int y, int mask){
	mask = mask & ( (1<<m) - 1 );
	if (y == m){
		y = 0;
		x++;
	}
	if (x == n) return 0;
	if (dp[x][y][mask] != -1) return dp[x][y][mask];
	
	int ret = serc(x, y + 1, (mask << 1) );
	
	if ((mask & 1) == 0 && y > 0){
		ret = max(ret, 1 + serc(x, y + 1, (mask << 1) | 3 ) );
	}
	
	if (( mask & (1 << (m - 1)) ) == 0 && x > 0){
		ret = max(ret, 1 + serc(x, y + 1, (mask << 1) | 1 ) );
	}
	
	return dp[x][y][mask] = ret;
}

int main(){
	
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < (1 << m); k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	
	printf("%d\n", serc(0, 0, 0));
	
	return 0;
}
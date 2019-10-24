//SPOJ MATSUM
//2D Binary Indexed Tree
#include<bits/stdc++.h>
using namespace std;
int N;
int BIT[1 << 11][1 << 11];
int ar[1 << 11][1 << 11];
void update2(int K, int x, int v) {
	while (x <= N) {
		BIT[K][x] += v;
		x += -x&x;
	}
}
void update(int x, int y, int v) {
	while (x <= N) {
		update2(x, y, v);
		x += -x&x;
	}
}
int query2(int K, int x) {
	int ret = 0;
	while (x > 0) {
		ret += BIT[K][x];
		x -= -x&x;
	}
	return ret;
}
int query(int x, int y) {
	int ret = 0;
	while (x > 0) {
		ret += query2(x, y);
		x -= -x&x;
	}
	return ret;
}
void clean() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			BIT[i][j] = 0;
			ar[i][j] = 0;
		}
	}
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &N);
		clean();
		while (1 < 2) {
			char str[50];
			int x, y, v, x1, y1;
			scanf("%s", str);
			if (!strcmp(str, "END")) break;
			else if (!strcmp(str, "SET")) {
				scanf("%d %d %d", &x, &y, &v);
				update(x+1, y+1, -ar[x][y]);
				ar[x][y] = v;
				update(x+1, y+1, v);
			}
			else {
				scanf("%d %d %d %d", &x, &y, &x1, &y1);
				printf("%d\n", query(x1+1, y1+1) - query(x, y1+1) - query(x1+1, y) + query(x, y));
			}
		}
		printf("\n");
	}
	return 0;
}
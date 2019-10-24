#include<bits/stdc++.h>
struct dat {
	int x, y, z;
	bool operator<(const dat& a) {
		if (x != a.x) return x < a.x;
		else if (y != a.y) return y < a.y;
		return z < a.z;
	}
};
const int N = 1000;
int ar[N][N];
int vis[N][N];
dat pq[N*N];
int gp;
void heapup(int x) {
	if (x == 0) return;
	int to = x;
	if (x / 2 > 0 && pq[to] < pq[x / 2]) to = x / 2;
	if (to != x) {
		dat tmp = pq[x];
		pq[x] = pq[to];
		pq[to] = tmp;
		heapup(to);
	}
}
void heapdown(int x) {
	if (x > gp) return;
	int to = x;
	if (x * 2 <= gp && pq[x * 2] < pq[to]) to = x * 2;
	if (x * 2 + 1 <= gp && pq[x * 2 + 1] < pq[to]) to = x * 2 + 1;
	if (to != x) {
		dat tmp = pq[x];
		pq[x] = pq[to];
		pq[to] = tmp;
		heapdown(to);
	}
}
void push(int a, int b, int c) {
	gp++;
	pq[gp].x = a;
	pq[gp].y = b;
	pq[gp].z = c;
	heapup(gp);
}
void pop() {
	dat tmp = pq[1];
	pq[1] = pq[gp];
	pq[gp] = tmp;
	gp--;
	heapdown(1);
}
dat top() {
	return pq[1];
}
bool empty() {
	if (gp == 0) return true;
	return false;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &ar[i][j]);
				vis[i][j] = (-1) ^ (1 << 31);
			}
		}
		push(ar[0][0], 0, 0);
		while (!empty()) {
			int c = top().x;
			int x = top().y;
			int y = top().z;
			pop();
			if (vis[x][y] != ((-1) ^ (1 << 31))) continue;
			vis[x][y] = c;
			if (x - 1 >= 0 && vis[x - 1][y] == ((-1) ^ (1 << 31))) push(c + ar[x - 1][y], x - 1, y);
			if (x + 1 < n && vis[x + 1][y] == ((-1) ^ (1 << 31))) push(c + ar[x + 1][y], x + 1, y);
			if (y - 1 >= 0 && vis[x][y - 1] == ((-1) ^ (1 << 31))) push(c + ar[x][y - 1], x, y - 1);
			if (y + 1 < m && vis[x][y + 1] == ((-1) ^ (1 << 31))) push(c + ar[x][y + 1], x, y + 1);
		}
		printf("%d\n", vis[n - 1][m - 1]);
	}
}
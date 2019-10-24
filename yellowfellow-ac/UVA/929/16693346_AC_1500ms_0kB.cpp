#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int ar[N][N];
int vis[N][N];
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
		priority_queue<pair<int,pair<int,int> > > pq;
		pq.push(pair<int,pair<int,int> >(-ar[0][0], pair<int,int>(0, 0)));
		while (!pq.empty()) {
			int c = pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			if (vis[x][y] != ((-1) ^ (1 << 31))) continue;
			vis[x][y] = -c;
			if (x - 1 >= 0 && vis[x - 1][y] == ((-1) ^ (1 << 31))) pq.push(pair<int,pair<int,int> >(c - ar[x - 1][y], pair<int,int>(x - 1, y)));
			if (x + 1 < n && vis[x + 1][y] == ((-1) ^ (1 << 31))) pq.push(pair<int,pair<int,int> >(c - ar[x + 1][y], pair<int,int>(x + 1, y)));
			if (y - 1 >= 0 && vis[x][y - 1] == ((-1) ^ (1 << 31))) pq.push(pair<int,pair<int,int> >(c - ar[x][y - 1], pair<int,int>(x, y - 1)));
			if (y + 1 < m && vis[x][y + 1] == ((-1) ^ (1 << 31))) pq.push(pair<int,pair<int,int> >(c - ar[x][y + 1], pair<int,int>(x, y + 1)));
		}
		printf("%d\n", vis[n - 1][m - 1]);
	}
}
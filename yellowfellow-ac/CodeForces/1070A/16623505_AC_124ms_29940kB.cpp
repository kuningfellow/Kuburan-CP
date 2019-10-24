#include<bits/stdc++.h>
using namespace std;
pair<int,pair<int,int> > vis[505][5005];
int main() {
	int d, s;
	scanf("%d%d", &d, &s);
	for (int i = 0; i < 505; i++) {
		for (int j = 0; j < 5005; j++) {
			vis[i][j].first = -1;
		}
	}
	queue<pair<int,pair<int,int> > > q;
	q.push(pair<int,pair<int,int> >(0, pair<int,int>(0, 0)));
	int init = 1;
	while (!q.empty()) {
		int siz = q.size();
		for (int i = 0; i < siz; i++) {
			int x = q.front().first;
			int a = q.front().second.first;
			int b = q.front().second.second;
			q.pop();
			for (int j = 0; j < 10; j++) {
				if (init && j == 0) continue;
				if (vis[(a*10+j)%d][b+j].first == -1 && b + j <= s) {
					vis[(a*10+j)%d][b+j] = pair<int,pair<int,int> >(j, pair<int,int>(a, b));
					q.push(pair<int,pair<int,int> >(j, pair<int,int>((a*10+j)%d, b+j)));
				}
			}
			init = 0;
		}
	}
	vector<int> hehe;
	int a = 0, b = s;
	while (a != 0 || b != 0) {
		hehe.push_back(vis[a][b].first);
		int ta = vis[a][b].second.first;
		int tb = vis[a][b].second.second;
		a = ta;
		b = tb;
	}
	for (int i = hehe.size()-1; i >= 0 ; i--) {
		printf("%d", hehe[i]);
	}
}
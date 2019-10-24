#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
using namespace std;
class solution {
private:
	vector<int>lis[31];
	map<int, int>cor;
	int idx, a, b, m;
	int _case = 1;
	bool mark[31];
public:
	solution() {
		while (scanf("%d", &m) && m != 0) {
			idx = 0;
			cor.clear();
			resetLis();
			for (int i = 0; i < m; i++) {
				scanf("%d %d", &a, &b);
				if (cor.count(a) == 0) cor[a] = idx++;
				if (cor.count(b) == 0) cor[b] = idx++;
				lis[cor[a]].push_back(cor[b]);
				lis[cor[b]].push_back(cor[a]);
			}
			while (1 < 2) {
				scanf("%d %d", &a, &b);
				if (a == 0 && b == 0) break;
				int ans = idx - fill();
				printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",_case++, ans, a, b);
			}
		}
	}
	void resetMark() {
		for (int i = 0; i < idx; i++) {
			mark[i] = false;
		}
	}
	int fill() {
		if (cor.count(a) == 0) return 0;
		resetMark();
		int vis = 0;
		queue<pair<int, int> >q;
		q.push(pair<int, int>(cor[a], b));
		while (!q.empty()) {
			int siz = q.size();
			for (int i = 0; i < siz; i++) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				if (mark[x]) continue;
				mark[x] = true;
				vis++;
				if (y == 0) continue;
				for (int j = 0; j < lis[x].size(); j++) {
					if (!mark[lis[x][j]]) {
						q.push(pair<int, int>(lis[x][j], y - 1));
					}
				}
			}
		}
		return vis;
	}
	void resetLis() {
		for (int i = 0; i < 30; i++) {
			lis[i].clear();
		}
	}
};

#ifndef L0C4L
int main() {
	solution();
	return 0;
}
#endif
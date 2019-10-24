#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
class solution {
private:
	char str[205][20];
	vector<int>lis[205];
	int mark[205];
	int tc;
	int idx;
	char S[50];
	int find(char* s) {
		for (int i = 0; i < idx; i++) {
			if (gap(str[i], s) == 0) return i;
		}
		return -1;
	}
	int gap(char* s1, char* s2) {
		int dif = 0;
		for (int i = 0; dif <= 1 && (s1[i] != '\0' || s2[i] != '\0'); i++) {
			if (s1[i] != s2[i]) dif++;
			if (s1[i] == '\0' && s2[i] != '\0') dif = 2;
			if (s1[i] != '\0' && s2[i] == '\0') dif = 2;
		}
		return dif;
	}
	void build() {
		for (int i = 0; i < idx; i++) {
			lis[i].clear();
		}
		for (int i = 0; i < idx - 1; i++) {
			for (int j = i + 1; j < idx; j++) {
				if (gap(str[i], str[j]) == 1) {
					lis[i].push_back(j);
					lis[j].push_back(i);
				}
			}
		}
	}
	int bfs(int d) {
		queue<int>q;
		int mov = 0;
		q.push(find(S));
		for (int i = 0; i < idx; i++) {
			mark[i] = 0;
		}
		while (!q.empty()) {
			int siz = q.size();
			for (int i = 0; i < siz; i++) {
				int x = q.front();
				q.pop();
				if (mark[x]) continue;
				mark[x] = 1;
				if (gap(str[x], S + d) == 0) {
					return mov;
				}
				for (int j = 0; j < lis[x].size(); j++) {
					if (!mark[lis[x][j]]) q.push(lis[x][j]);
				}
			}
			mov++;
		}
	}
public:
	solution() {
		scanf("%d", &tc);
		while (tc--) {
			idx = 0;
			while (scanf("%[\n]", str[0]));
			while (1 < 2) {
				scanf("%s", str[idx]);
				if (str[idx][0] == '*') break;
				idx++;
			}
			while (scanf("%[\n]", S));
			build();
			while (1 < 2) {
				S[0] = '\0';
				scanf("%[^\n]", S);
				getchar();
				if (strlen(S) == 0) break;
				for (int i = 0; S[i] != '\0'; i++) {
					if (S[i] == ' ') {
						S[i] = '\0';
						int ans = bfs(i+1);
						S[i] = ' ';
						printf("%s %d\n", S, ans);
					}
				}
			}
			if (tc) printf("\n");
		}
	}
};

#ifndef L0C4L
int main() {
	solution();
	return 0;
}
#endif
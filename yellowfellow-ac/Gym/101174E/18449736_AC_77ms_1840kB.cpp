#include<stdio.h>
#include<queue>

using namespace std;

typedef long long int LL;

const LL MOD = 1000003;

char lis[62];

namespace aho {
	int nxt[1005][62];
	int mark[1005];
	int sl[1005];
	int kmp[1005];
	int sptr;
	void init() {
		sptr = 0;
		for (int i = 0; i < 1005; i++) {
			for (int j = 0; j < 62; j++) {
				nxt[i][j] = -1;
			}
			sl[i] = kmp[i] = mark[i] = 0;
		}
	}
	int to(char x) {
		if (x == 'o' || x == 'O') return '0' - '0' + 52;
		else if (x == 'i' || x == 'I') return '1' - '0' + 52;
		else if (x == 'e' || x == 'E') return '3' - '0' + 52;
		else if (x == 's' || x == 'S') return '5' - '0' + 52;
		else if (x == 't' || x == 'T') return '7' - '0' + 52;
		else if (x >= 'a' && x <= 'z') return x - 'a';
		else if (x >= 'A' && x <= 'Z') return x - 'A';
		else if (x >= '0' && x <= '9') return x - '0' + 52;
	}
	void add(char *str) {
		int id = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			if (nxt[id][to(str[i])] == -1) {
				nxt[id][to(str[i])] = ++sptr;
			}
			id = nxt[id][to(str[i])];
		}
		mark[id] = 1;
	}
	void build() {
		queue<int>q;
		for (int i = 0; i < 62; i++) {
			if (nxt[0][i] != -1) q.push(nxt[0][i]);
		}
		while (!q.empty()) {
			int siz = q.size();
			for (int i = 0; i < siz; i++) {
				int x = q.front();
				q.pop();
				for (int j = 0; j < 62; j++) {
					if (nxt[x][j] == -1) continue;
					int k = kmp[x];
					while (k != 0 && nxt[k][j] == -1) k = kmp[k];
					if (nxt[k][j] != -1) k = nxt[k][j];
					kmp[nxt[x][j]] = k;
					if (mark[k] == 1) sl[nxt[x][j]] = k;
					else sl[nxt[x][j]] = sl[k];
					q.push(nxt[x][j]);
				}
			}
		}
	}
}

int get(int x) {
	if (x < 26) return 1;
	else if (x < 52) return 2;
	else return 4;
}

LL dp[25][1005][8];
int A, B;
LL serc(int x, int p, int mask) {
	if (x > B) return 0;
	if (dp[x][p][mask] != -1) return dp[x][p][mask];
	int chk = p, foun = 0;
	while (chk != 0 && !foun) {
		if (aho::mark[chk] == 1) foun = 1;
		chk = aho::sl[chk];
	}
	if (foun) return 0;
	
	dp[x][p][mask] = 0;
	if (x >= A && x <= B && mask == 7) dp[x][p][mask] = 1;
	for (int i = 0; i < 62; i++) {
		int t = p;
		while (t != 0 && aho::nxt[t][aho::to(lis[i])] == -1) {
			t = aho::kmp[t];
		}
		if (aho::nxt[t][aho::to(lis[i])] != -1) t = aho::nxt[t][aho::to(lis[i])];
		int chk = t, foun = 0;
		while (chk != 0 && !foun) {
			if (aho::mark[chk] == 1) foun = 1;
			chk = aho::sl[chk];
		}
		if (foun) continue;
		dp[x][p][mask] = (dp[x][p][mask] + serc(x + 1, t, mask | get(i))) % MOD;
	}
	return dp[x][p][mask];
}
int main() {
	aho::init();
	for (int i = 0; i < 26; i++) lis[i] = i + 'a';
	for (int i = 0; i < 26; i++) lis[i + 26] = i + 'A';
	for (int i = 0; i < 10; i++) lis[i + 52] = i + '0';
		
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 1005; j++) {
			for (int k = 0; k < 8; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	int n;
	scanf("%d %d", &A, &B);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char str[50];
		scanf("%s", str);
		aho::add(str);
	}
	aho::build();
	printf("%lld\n", serc(0, 0, 0));
	return 0;
}
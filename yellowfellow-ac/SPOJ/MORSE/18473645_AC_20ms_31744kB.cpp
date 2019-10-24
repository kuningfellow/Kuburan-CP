#include<stdio.h>
#include<string.h>

typedef long long int LL;

char morse[26][5] = {".-", "-...", "-.-.", "-..",
".", "..-.", "--.", "....",
"..", ".---", "-.-", ".-..",
"--", "-.", "---", ".--.",
"--.-", ".-.", "...", "-",
"..-", "...-", ".--", "-..-",
"-.--", "--.."};

int to(char x) {
	if (x == '.') return 0;
	else return 1;
}

namespace trie {
	int nxt[800005][2];
	int mark[800005];
	int gptr;
	void init() {
		gptr = 0;
		for (int i = 0; i < 800005; i++) {
			nxt[i][0] = nxt[i][1] = -1;
			mark[i] = 0;
		}
	}
	void add(const char *str) {
		int pos = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			if (nxt[pos][to(str[i])] == -1)
				nxt[pos][to(str[i])] = ++gptr;
			pos = nxt[pos][to(str[i])];
		}
		mark[pos]++;
	}
}

LL dp[10005][85];
char str[10005];

LL serc(int x, int p, int t) {
	if (str[x] == '\0') return trie::mark[t];
	if (trie::nxt[ t ][ to(str[x]) ] == -1) return 0;
	t = trie::nxt[ t ][ to(str[x]) ];
	if (dp[x][p] != -1) return dp[x][p];
	dp[x][p] = 0;
	if (trie::mark[t]) dp[x][p] += serc(x + 1, 0, 0) * trie::mark[t];
	dp[x][p] += serc(x + 1, p + 1, t);
	return dp[x][p];
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		trie::init();
		scanf("%s", str);
		for (int i = strlen(str); i >= 0; i--) {
			for (int j = 0; j < 85; j++) {
				dp[i][j] = -1;
			}
		}
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			char res[85];
			res[0] = '\0';
			char tmp[50];
			scanf("%s", tmp);
			for (int j = 0; tmp[j] != '\0'; j++) {
				strcat(res, morse[tmp[j] - 'A']);
			}
			trie::add(res);
		}
		printf("%lld\n", serc(0, 0, 0));
	}
	return 0;
}
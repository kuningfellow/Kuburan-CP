#include<stdio.h>
#define TC int TC;scanf("%d",&TC);while(TC--)

int pref[2005][2005];

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b) {
	return -min(-a, -b);
}

int query(int x, int y, int l) {
	return pref[x][y] - pref[x][y - l - 1] - pref[x - l - 1][y] + pref[x - l - 1][y - l - 1];
}

template<typename T>
void scanum(T& a) {
	bool neg = 0;
	char c;
	a = 0;
	double mul = 1;
	while (1) {
		c = getchar();
		if (c == EOF || c == '-' || c == '.' || (c >= '0' && c <= '9')) break;
	}
	if (c == '-') neg = 1;
	else if (c == '.') mul = 0.1;
	else a = c - '0';
	while (1) {
		c = getchar();
		if (c == '.') mul = 0.1;
		else if (c < '0' || c > '9') break;
		else {
			if (mul < 1) a = a + mul * (c - '0');
			else a = a * 10 + (c - '0');
			if (mul < 1) mul *= 0.1;
		}
	}
	if (neg) a *= -1;
}

int main() {
	TC {
		int n, m;
		scanum(n);
		scanum(m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanum(pref[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				pref[i][j] += pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1];
			}
		}
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			int p = 1;
			for (int j = 1; j <= m; j++) {
				if (i + j - 1 > n) break;
				while (query(i + j - 1, j,  j - p) > 1) p++;
				ans = max(ans, j - p);
			}
		}
		for (int i = 1; i <= m; i++) {
			int p = 1;
			for (int j = 1; j <= n; j++) {
				if (i + j - 1 > m) break;
				while (query(j, i + j - 1, j - p) > 1) p++;
				ans = max(ans, j - p);
			}
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}
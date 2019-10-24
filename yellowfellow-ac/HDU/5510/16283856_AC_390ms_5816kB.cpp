#include<bits/stdc++.h>
using namespace std;
int kmp[501][2001];
char str[501][2001];
int mark[501];
void makekmp(int a) {
	int j = 0;
	int l = strlen(str[a]);
	kmp[a][0] = 0;
	for (int i = 1; i < l; i++) {
		while (j - 1 >= 0 && str[a][j] != str[a][i]) {
			j = kmp[a][j - 1];
		}
		if (str[a][j] == str[a][i]) {
			j++;
		}
		kmp[a][i] = j;
	}
}
bool instring(int a, int b) {
	int j = 0;
	int l = strlen(str[a]);
	int L = strlen(str[b]);
	for (int i = 0; i < L; i++) {
		while (j - 1 >= 0 && str[a][j] != str[b][i]) {
			j = kmp[a][j - 1];
		}
		if (str[a][j] == str[b][i]) {
			j++;
		}
		if (j == l) {
			return true;
		}
	}
	return false;
}
int main() {
	int tc, kas = 1;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", str[i]);
			makekmp(i);
			mark[i] = 0;
		}
		int ans = -2;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (mark[j]) continue;
				if (instring(j, i)) {
					mark[j] = 1;
				}
				else {
					ans = i;
					break;
				}
			}
		}
		printf("Case #%d: %d\n", kas++, ans + 1);
	}
}
#include<stdio.h>
#include<string.h>
class solve {
private:
	int kmp[80];
	char str[81];
public:
	solve() {
		scanf("%s", str);
		int x = build();
		printf("%d\n", x - (x % (x - kmp[x-1]) ? 0 : kmp[x-1]));
	}
	int build() {
		kmp[0] = 0;
		for (int i = 1, j = 0;; i++) {
			if (str[i] == '\0') return i;
			while (j > 0 && str[j] != str[i]) j = kmp[j - 1];
			if (str[i] == str[j]) j++;
			kmp[i] = j;
		}
	}
};
int main() {
	int tc;
	scanf("%d", &tc);
	do {
		solve();
	} while (--tc && printf("\n"));
	return 0;
}
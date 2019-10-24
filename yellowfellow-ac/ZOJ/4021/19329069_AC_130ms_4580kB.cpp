#include<stdio.h>

int lis[500005][2];
char str[500005];
int siz;

int main() {
	int tc, st = 0, ret, cnt;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", str);
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == 'T') lis[siz][0] = st, lis[siz++][1] = 1;
			else if (str[i] == 'F') lis[siz][0] = st, lis[siz++][1] = 0;
			else if (str[i] == '!') lis[siz][0] = st, lis[siz++][1] = -1;
			else if (str[i] == '(') st++;
			else if (str[i] == ')') {
				ret = siz, cnt = 0;
				while (siz && lis[siz - 1][0] == st) {
					if (lis[siz - 1][1] == -3) {
						if (ret > cnt) ret = cnt;
						cnt = 0;
					}
					else if (lis[siz - 1][1] == 0) cnt++;
					siz--;
				}
				if (ret > cnt) ret = cnt;
				st--;
				lis[siz][0] = st, lis[siz++][1] = ret > 0 ? 0 : 1;
			}
			else if (str[i] == '&') lis[siz][0] = st, lis[siz++][1] = -2;
			else if (str[i] == '|') lis[siz][0] = st, lis[siz++][1] = -3;
			while (siz > 1) {
				int a = lis[siz - 1][0];
				int b = lis[siz - 1][1];
				siz--;
				if (lis[siz - 1][0] == a && b >= 0 && lis[siz - 1][1] == -1) {
					lis[siz - 1][1] = 1 ^ b;
				}
				else {
					lis[siz][0] = a, lis[siz++][1] = b;
					break;
				}
			}
		}
		ret = 2, cnt = 0;
		while (siz && lis[siz - 1][0] == st) {
			if (lis[siz - 1][1] == -3) {
				if (ret > cnt) ret = cnt;
				cnt = 0;
			}
			else if (lis[siz - 1][1] == 0) cnt++;
			siz--;
		}
		if (ret > cnt) ret = cnt;
		printf("%d\n", ret);
	}
	return 0;
}
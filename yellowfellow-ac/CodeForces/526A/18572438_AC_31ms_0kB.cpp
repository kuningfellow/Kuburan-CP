#include<stdio.h>

char str[105];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	int good = 0;
	for (int i = 1; i < n && !good; i++) {
		for (int j = 0; j < n; j++) {
			int tmp = 0;
			for (int k = 0; k < n; k += i) {
				if (str[j + k] == '*') tmp++;
				else break;
			}
			if (tmp >= 5) {
				good = 1;
				break;
			}
		}
	}
	if (good) printf("yes\n");
	else printf("no\n");
	return 0;
}
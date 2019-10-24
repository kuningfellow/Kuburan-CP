#include<stdio.h>

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		char str[50];
		int cnt[3] = {0, 0, 0};
		for (int i = 0; i < 3; i++) {
			scanf("%s", &str);
			for (int j = 0; j < 10; j++) {
				cnt[i] += str[j] - '0';
			}
		}
		int best = 0;
		for (int i = 0; i < 10; i++) {
			int val = 1;
			int tmp = 0;
			for (int j = 0; j < 3; j++) {
				tmp += cnt[j];
				if (cnt[j] < i) {
					val = 0;
					break;
				}
			}
			if (!val) break;
			tmp -= i * 3;
			if (tmp >= 20 - i*2) tmp -= 20 - i*2;
			else if (tmp >= 10 - i) tmp = 20 - i*2 - tmp;
			best = max(best, tmp + i);
		}
		for (int i = 0; i < 10; i++) {
			if (best > 0) printf("1"), best--;
			else printf("0");
		}
		printf("\n");
	}
	return 0;
}
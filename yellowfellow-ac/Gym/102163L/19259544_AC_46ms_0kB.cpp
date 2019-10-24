#include<stdio.h>
#define TC int TC; scanf("%d", &TC); while(TC--)

int main() {
	TC {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			int cnt = 0;
			while (x) {
				if (x & 1) cnt++;
				x /= 2;
			}
			printf("%d ", cnt);
		}
		printf("\n");
	}
	return 0;
}
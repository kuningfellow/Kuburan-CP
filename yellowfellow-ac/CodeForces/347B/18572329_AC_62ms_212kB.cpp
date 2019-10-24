#include<stdio.h>

int ar[100005];

int main() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
		if (ar[i] == i) ans++;
	}
	int best = 0;
	for (int i = 0; i < n; i++) {
		if (ar[i] != i) {
			if (ar[ar[i]] == i) {
				best = 2;
			}
			else {
				if (best == 0) best = 1;
			}
		}
	}
	ans += best;
	printf("%d\n", ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int ar[1005];
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &ar[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				for (int k = j+1; k < n; k++) {
					if (i == k) continue;
					ans = max(ans, (ar[j]+ar[k])^ar[i]);
				}
			}
		}
		printf("%d\n", ans);
	}
}
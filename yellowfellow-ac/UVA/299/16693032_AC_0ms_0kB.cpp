#include<bits/stdc++.h>
using namespace std;
const int N = 50;
int ar[N];
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
			int found;
			for (int j = i; j < n; j++) {
				found = j;
				if (ar[j] == i+1) {
					break;
				}
			}
			ans += found - i;
			for (int j = found; j > i; j--) {
				ar[j] = ar[j-1];
			}
			ar[i] = i+1;
		}
		printf("Optimal train swapping takes %d swaps.\n", ans);
	}
}
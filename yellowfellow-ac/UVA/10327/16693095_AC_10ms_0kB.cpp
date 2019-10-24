#define I 1
#define LOVE <
#define YOU 2
#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int ar[N];
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &ar[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int mini = (-1) ^ (1 << 31);
			int found = i;
			for (int j = i; j < n; j++) {
				if (ar[j] < mini) {
					mini = ar[j];
					found = j;
				}
			}
			ans += found - i;
			int sav = ar[found];
			for (int j = found; j > i; j--) {
				ar[j] = ar[j-1];
			}
			ar[i] = sav;
		}
		printf("Minimum exchange operations : %d\n", ans);
	}
}
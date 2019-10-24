#define I 1
#define LOVE <
#define YOU 2
#include<bits/stdc++.h>
using namespace std;
vector<int> ar;
vector<int> br;
int main() {
	while (I LOVE YOU) {
		ar.clear();
		br.clear();
		int n, d, r;
		scanf("%d%d%d", &n, &d, &r);
		if (n == 0 && d == 0 && r == 0) break;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			ar.push_back(a);
		}
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			br.push_back(a);
		}
		sort(ar.begin(), ar.end());
		sort(br.begin(), br.end());
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += r * max(ar[i] + br[n-1-i] - d, 0);
		}
		printf("%d\n", ans);
	}
}
#include<bits/stdc++.h>
using namespace std;
int main() {
	int tc, kas = 1;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		priority_queue<int>eval;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			eval.push(a);
		}
		int ans = 0;
		int cnt = 0;
		while (!eval.empty()) {
			ans += eval.top();
			cnt++;
			if (cnt == 3) {
				ans -= eval.top();
			}
			eval.pop();
			cnt %= 3;
		}
		printf("Case #%d: %d\n", kas++, ans);
	}
}
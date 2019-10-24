#include<stdio.h>
#include<queue>
typedef long long int LL;
using namespace std;
class solution {
private:
	priority_queue<LL>lis;
	void solve() {
		int n;
		LL ans = 0;
		scanf("%d", &n);
		while (n--) {
			LL a;
			scanf("%lld", &a);
			lis.push(-a);
		}
		while (lis.size() > 1) {
			LL a = lis.top();
			lis.pop();
			LL b = lis.top();
			lis.pop();
			ans -= a + b;
			lis.push(a + b);
		}
		lis.pop();
		printf("%lld\n", ans);
	}
public:
	solution() {
		int tc;
		scanf("%d", &tc);
		while (tc--) {
			solve();
		}
	}
};

#ifndef L0C4L
int main() {
	solution();
	return 0;
}
#endif
#include<bits/stdc++.h>
typedef long long int LL;
using namespace std;
vector<LL> lis;
vector<LL> lis2;
int main() {
	int tc, kas = 1;
	scanf("%d", &tc);
	while (tc--) {
		int l, n, m;
		scanf("%d %d %d", &l, &n, &m);
		lis.clear();
		lis2.clear();
		priority_queue<pair<LL,int> >pq;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			pq.push(pair<LL,int>(-a, a));
		}
		int tmp = 0;
		while (tmp < l) {
			lis.push_back(-pq.top().first);
			LL eval = pq.top().first;
			int mul = pq.top().second;
			pq.pop();
			pq.push(pair<LL,int>(eval - mul, mul));
			tmp++;
		}
		while (!pq.empty()) {
			pq.pop();
		}
		for (int i = 0; i < m; i++) {
			int a;
			scanf("%d", &a);
			pq.push(pair<LL,int>(-a, a));
		}
		tmp = 0;
		while (tmp < l) {
			lis2.push_back(-pq.top().first);
			LL eval = pq.top().first;
			int mul = pq.top().second;
			pq.pop();
			pq.push(pair<LL,int>(eval - mul, mul));
			tmp++;
		}
		while (!pq.empty()) {
			pq.pop();
		}
		LL ans = 0;
		for (int i = 0; i < l; i++) {
			ans = max(ans, lis[i] + lis2[l - 1 - i]);
		}
		printf("Case #%d: %lld\n", kas++, ans);
	}
}
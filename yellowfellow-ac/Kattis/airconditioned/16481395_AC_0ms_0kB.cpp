#include<bits/stdc++.h>
using namespace std;
struct dat {
	int l, r;
	bool operator<(const dat& a) {
		if (l != a.l) return l < a.l;
		else return r < a.r;
	}
};
vector<dat> lis;
int main() {
	int n;
	dat dum;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &dum.l, &dum.r);
		lis.push_back(dum);
	}
	sort(lis.begin(), lis.end());
	int ans = 1;
	int prev = 0;
	for (int i = 1; i < n; i++) {
		if (lis[i].l > lis[prev].r) {
			ans++;
			prev = i;
		}
		else if (lis[i].r < lis[prev].r) {
			prev = i;
		}
	}
	printf("%d\n", ans);
}
#include<bits/stdc++.h>
using namespace std;
int par[500005];
int siz[500005];
int finpar(int x) {
	if (par[x] == x) return x;
	return finpar(par[x]);
}
int main() {
	int ans = 0;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 500005; i++) {
		par[i] = i;
		siz[i] = 1;
	}
	while (n--) {
		int m;
		scanf("%d", &m);
		vector<int> lis;
		map<int,int> cnt;
		for (int i = 0; i < m; i++) {
			int a;
			scanf("%d", &a);
			lis.push_back(a);
			cnt[finpar(a)]++;
		}
		int skip = 0;
		for (int i = 0; i < m; i++) {
			if (siz[finpar(lis[i])] != cnt[finpar(lis[i])]) {
				skip = 1;
				break;
			}
		}
		if (skip) continue;
		for (int i = 1; i < m; i++) {
			if (finpar(lis[0]) != finpar(lis[i])) {
				siz[finpar(lis[0])] += siz[finpar(lis[i])];
				par[finpar(lis[i])] = finpar(lis[0]);
			}
		}
		ans++;
	}
	printf("%d\n", ans);
}
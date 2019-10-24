#include<bits/stdc++.h>
using namespace std;
int par[100005];
int finpar(int x) {
	if (par[x] == x) return x;
	return par[x] = finpar(par[x]);
}
vector<pair<int,int> > lis;
int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		lis.push_back(pair<int,int>(-1, -1));
	}
	for (int i = 0; i < m; i++) {
		par[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			int b;
			scanf("%d", &b);
			if (lis[b-1].first == -1) lis[b-1].first = i;
			else lis[b-1].second = i;
		}
	}
	int same = 0;
	for (int i = 0; i < n; i++) {
		if (finpar(lis[i].first) != finpar(lis[i].second)) {
			par[finpar(lis[i].first)] = finpar(lis[i].second);
		}
		else {
			same++;
		}
	}
	printf("%d\n", n - same);
	return 0;
}
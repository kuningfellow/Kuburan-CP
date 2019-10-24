#define I 1
#define LOVE <
#define YOU 2
#include<bits/stdc++.h>
using namespace std;
vector<int> lis;
vector<pair<int,pair<int,int> > > ans;
vector<pair<int,int> > query;
int main() {
	int kas = 1;
	while (I LOVE YOU) {
		int n, q;
		lis.clear();
		query.clear();
		ans.clear();
		scanf("%d%d", &n, &q);
		if (n == 0 && q == 0) break;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			lis.push_back(a);
		}
		for (int i = 0; i < q; i++) {
			int a;
			scanf("%d", &a);
			query.push_back(pair<int,int>(a, i));
		}
		int j = 0;
		sort(lis.begin(), lis.end());
		sort(query.begin(), query.end());
		for (int i = 0; i < n && j < q; i++) {
			while (j < q && lis[i] >= query[j].first) {
				if (lis[i] == query[j].first) ans.push_back(pair<int,pair<int,int> >(query[j].second, pair<int,int>(query[j].first, i + 1)));
				else ans.push_back(pair<int,pair<int,int> >(query[j].second, pair<int,int>(query[j].first, -1)));
				j++;
			}
		}
		while (j < q) {
			ans.push_back(pair<int,pair<int,int> >(query[j].second, pair<int,int>(query[j].first, -1)));
			j++;
		}
		sort(ans.begin(), ans.end());
		printf("CASE# %d:\n", kas++);
		for (int i = 0; i < q; i++) {
			printf("%d ", ans[i].second.first);
			if (ans[i].second.second == -1) printf("not found\n");
			else printf("found at %d\n", ans[i].second.second);
		}
	}
}
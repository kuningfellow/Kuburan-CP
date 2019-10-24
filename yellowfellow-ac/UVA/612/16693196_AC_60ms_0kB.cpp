#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > ord;
char str[100][51];
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		ord.clear();
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%s", str[i]);
			ord.push_back(pair<int,int>(0, i));
			for (int j = 0; j < n; j++) {
				for (int k = j+1; k < n; k++) {
					if (str[i][j] > str[i][k]) {
						ord[i].first++;
					}
				}
			}
		}
		sort(ord.begin(), ord.end());
		for (int i = 0; i < m; i++) {
			printf("%s\n", str[ord[i].second]);
		}
		if (tc) printf("\n");
	}
}
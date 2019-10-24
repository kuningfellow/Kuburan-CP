#include<stdio.h>
#include<vector>
#include<algorithm>

typedef long long int LL;
using namespace std;

vector<pair<int,int> > tmp;
vector<pair<int,int> > lis;
vector<int> hull;
int mark[1000005];
LL dp[1000005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		tmp.push_back(pair<int,int>(x, y));
	}
	
	sort(tmp.begin(), tmp.end());
	for (int i = n-1, j = -1; i >= 0; i--) {
		if (j != -1 && tmp[i].first <= tmp[j].first && tmp[i].second <= tmp[j].second) continue;
		mark[i] = 1;
		j = i;
	}
	for (int i = n-1; i >= 0; i--) {
		if (mark[i]) lis.push_back(tmp[i]);
	}
	
	for (int i = 0, k = 0; i < lis.size(); i++) {
		while (hull.size() > 1) {
			int b = hull[hull.size() - 1];
			hull.pop_back();
			int a = hull[hull.size() - 1];		
			double x2 = (dp[b] - dp[i]) / ((double) lis[i].first - lis[b].first);
			double x1 = (dp[a] - dp[i]) / ((double) lis[i].first - lis[a].first);
			if (x1 < x2) {
				hull.push_back(b);
				break;
			}
		}
		hull.push_back(i);
		
		dp[i+1] = dp[hull[k]] + (LL)lis[hull[k]].first * lis[i].second;
		while (k + 1 < hull.size() && dp[hull[k+1]] + (LL)lis[hull[k+1]].first * lis[i].second < dp[i+1]) {
			k++;
			dp[i+1] = dp[hull[k]] + (LL)lis[hull[k]].first * lis[i].second;
		}
	}
	
	printf("%lld\n", dp[lis.size()]);
	return 0;
}
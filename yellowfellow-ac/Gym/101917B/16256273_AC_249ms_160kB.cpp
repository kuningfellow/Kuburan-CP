#include<bits/stdc++.h>
using namespace std;
struct dat{
	long long int A, B, C;
	bool operator<(const dat& a){
		return A < a.A;
	}
};
vector<dat> lis;
vector<dat> eval;
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	dat dum;
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &dum.A, &dum.B, &dum.C);
		lis.push_back(dum);
	}
	long long int ans = (-1) ^ (1ll << 63);
	for (int i = 0; i < n; i++) {
		eval.clear();
		for (int j = 0; j < n; j++) {
			if (lis[j].B <= lis[i].B) eval.push_back(lis[j]);
		}
		sort(eval.begin(), eval.end());
		priority_queue<long long int> check;
		for (int j = 0; j < eval.size(); j++) {
			check.push(eval[j].C);
			if (check.size() > k) check.pop();
			if (check.size() == k) {
				ans = min(ans, eval[j].A + lis[i].B + check.top());
			}
		}
	}
	printf("%lld\n", ans);
}
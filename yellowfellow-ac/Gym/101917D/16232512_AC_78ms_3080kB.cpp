#include<bits/stdc++.h>
using namespace std;
struct dat{
	int c;
	double r;
	bool operator<(const dat& a){
		return (double)c + r*a.c < (double)a.c + a.r*c;
	}
};
int main(){
	int n;
	double w;
	scanf("%d%lf", &n, &w);
	vector<dat>lis;
	dat dum;
	for (int i = 0; i < n; i++) {
		scanf("%d%lf", &dum.c, &dum.r);
		lis.push_back(dum);
	}
	sort(lis.begin(), lis.end());
	double ans = 0;
	for (int i = 0; i < n; i++) {
		ans += w * lis[i].c;
		w *= lis[i].r;
	}
	printf("%.8f\n", ans);
}
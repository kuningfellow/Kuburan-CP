#include<bits/stdc++.h>
#define SQUARE(x) ((x)*(x))
using namespace std;
double cross(pair<double,double> a, pair<double,double> b, pair<double,double> c){
	double x1 = b.first - a.first;
	double x2 = b.second - a.second;
	double u1 = c.first - a.first;
	double u2 = c.second - a.second;
	return x1 * u2 - x2 * u1;
}
vector<pair<double,double> > lis;
vector<pair<double,double> > take;
int main(){
	int n;
	double r;
	scanf("%d%lf", &n, &r);
	for (int i = 0; i < n; i++) {
		double a, b;
		scanf("%lf%lf", &a, &b);
		lis.push_back(pair<double,double>(a, b));
	}
	sort(lis.begin(), lis.end());
	for (int i = 0; i < n; i++) {
		while (take.size() > 1 && cross(take[take.size()-2], take[take.size()-1], lis[i]) > 1e-9) {
			take.pop_back();
		}
		take.push_back(lis[i]);
	}
	int s = take.size();
	for (int i = n-1; i >= 0; i--) {
		while (take.size() > s && cross(take[take.size()-2], take[take.size()-1], lis[i]) > 1e-9) {
			take.pop_back();
		}
		take.push_back(lis[i]);
	}
	s = take.size();
	double ans = 0;
	for (int i = 0; i < s; i++) {
		ans += sqrt(SQUARE(take[i].first - take[(i+1)%s].first) + SQUARE(take[i].second - take[(i+1)%s].second));
	}
	ans += acos(-1) * 2 * r;
	printf("%.2f\n", ans);
}
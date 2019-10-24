#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
struct point {
	int x, y;
};
struct dat {
	int a, b, c;
};
int cross(point& a, point& b, point& c) {
	int v1 = b.x - a.x;
	int v2 = b.y - a.y;
	int u1 = c.x - a.x;
	int u2 = c.y - a.y;
	return (v1*u2 - v2*u1);
}
double dist(point& a, point& b) {
	int v1 = b.x - a.x;
	int v2 = b.y - a.y;
	double len = sqrt((double)v1*v1 + (double)v2*v2);
	return len;
}
int vis[101];
vector<point> pts;
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		point dum;
		pts.clear();
		for (int i = 0; i < n; i++) {
			vis[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &dum.x, &dum.y);
			pts.push_back(dum);
		}
		int val = 1;
		dat D;
		D.a = 0;
		D.b = -1;
		D.c = -1;
		double prev = -69;
		int pref = -1;
		for (int i = 0; i < n; i++) {
			vis[D.a] = 1;
			double best = (-1) ^ (1 << 31);
			int pick = -1;
			for (int j = 0; j < n; j++) {
				int term = 0;
				if (i == n-1 && j == 0) term = 1;
				if (!term && vis[j] == 1) continue;
				double d = dist(pts[D.a], pts[j]);
				if (d < best) {
					pick = j;
					best = d;
				}
			}
			if (prev >= 0 && fabs(best - prev) > 1e-9) {
				val = 0;
				break;
			}
			else {
				prev = best;
			}
			if (D.c != -1 && cross(pts[D.c], pts[D.b], pts[D.a]) != cross(pts[D.b], pts[D.a], pts[pick])) {
				val = 0;
				break;
			}
			vis[pick] = 1;
			D.c = D.b;
			D.b = D.a;
			D.a = pick;
		}
		printf("%s\n", val?"YES":"NO");
	}
}
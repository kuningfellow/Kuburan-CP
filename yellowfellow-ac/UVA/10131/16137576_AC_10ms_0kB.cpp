//UVA 10131 Is Bigger Smarter?
#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int bt[1005][1005];
struct dat {
	int w, s, idx;
	bool operator<(const dat& a){
		if (w != a.w) return w < a.w;
		else if (s != a.s) return s > a.s;
		return idx < a.idx;
	}
};
dat ar[1005];
int n;
int serc(int x, int p){
	if (x == n){
		return 0;
	}
	if (dp[x][p] != -1){
		return dp[x][p];
	}
	dp[x][p] = serc(x+1, p);
	if ( ( p == 1000 || ar[x].s < ar[p].s ) && ar[x].w > ar[p].w){
		int ret = 1 + serc(x+1, x);
		if (ret >= dp[x][p]){
			dp[x][p] = ret;
			bt[x][p] = 1;
		}
	}
	return dp[x][p];
}
int main(){
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF){
		ar[n].w = a;
		ar[n].s = b;
		ar[n].idx = n;
		n++;
	}
	sort(ar, ar + n);
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			dp[i][j] = -1;
		}
	}
	int ans = serc(0, 1000);
	printf("%d\n", ans);
	int x = 0;
	int p = 1000;
	while (x < n){
		if (bt[x][p] == 1){
			printf("%d\n", ar[x].idx + 1);
			p = x;
		}
		x++;
	}
}

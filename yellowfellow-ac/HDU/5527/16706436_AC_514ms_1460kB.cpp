#include<bits/stdc++.h>
using namespace std;
int cnt[10];
int maxi[10];
int ar[10] = {1, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
map<int,int>vis[10];
int p;

int serc(int x, int tot) {
	if (tot == 0) return 0;
	if (x < 0) return -1000000000;
	if (vis[x].count(tot) != 0) return vis[x][tot];
	bool delta = max(0,tot - maxi[x-1]) % ar[x]  ; 
	int red = max(0,tot - maxi[x-1])/ar[x] + delta;
	int ret = -1000000000;
	if( red <= cnt[x] ) ret = red + serc(x-1,tot - ar[x] * red );
	if( red + 1 <= cnt[x] )ret = max(ret, red + 1 + serc(x-1, tot - ar[x] * (red+1) ));
	return vis[x][tot] = ret;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &p);
		for (int i = 0; i < 10; i++) {
			scanf("%d", &cnt[i]);
			vis[i].clear();
		}
		for (int i = 0; i < 10; i++) {
			maxi[i] = ar[i]*cnt[i];
			if (i > 0) maxi[i] += maxi[i-1];
		}
		int ans = serc(9, p);
		if (ans < 0) ans = -1;
		printf("%d\n", ans);
	}
}
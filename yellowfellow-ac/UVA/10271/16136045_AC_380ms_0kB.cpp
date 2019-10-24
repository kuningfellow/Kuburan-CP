//UVA 10271 Chopsticks
#include<bits/stdc++.h>
using namespace std;
#define SQUARE(x) ((x)*(x))
typedef long long int LL;
LL ar[5005];
LL dp[5005][1010];
int N;
LL serc(int x, int cnt){
	if (N - x < cnt * 3) return (-1) ^ (1 << 31);
	if (x >= N) {
		if (cnt == 0) return 0;
		return (-1) ^ (1 << 31);
	}
	if (dp[x][cnt] != -1) return dp[x][cnt];
	return dp[x][cnt] = min(serc(x+1, cnt), SQUARE(ar[x]-ar[x+1]) + serc(x + 2, cnt - 1));
}
int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d%d", &n, &N);
		for (int i = 0; i < N; i++) {
			scanf("%lld", &ar[i]);
		}
		sort(ar, ar + N);
		n += 8;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j] = -1;
			}
		}
		printf("%lld\n", serc(0, n));
	}
}
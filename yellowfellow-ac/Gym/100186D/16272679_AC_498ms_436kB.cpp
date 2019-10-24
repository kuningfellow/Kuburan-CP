#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL ar[1005];
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int d, n, m;
	scanf("%d%d%d", &n, &d, &m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < d; j++){
			LL a;
			scanf("%lld", &a);
			ar[j] += a;
		}
	}
	LL ans = -1;
	int best = -1;
	LL tmp = 0;
	for (int i = 0; i < d; i++){
		tmp += ar[i];
		if (i + 1 >= m){
			if (i - m >= 0) tmp -= ar[i-m];
			if (tmp > ans){
				ans = tmp;
				best = i - m + 2;
			}
		}
	}
	printf ("%d %lld\n", best, ans);
}
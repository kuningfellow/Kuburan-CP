#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ULL;
int main(){
	ULL n, s;
	scanf("%llu%llu", &n, &s);
	ULL l = 0;
	ULL r = n;
	ULL ans = n + 1;
	while (l <= r) {
		ULL mid = (l + r) / 2;
		ULL eval = mid;
		ULL tot = 0;
		while (eval > 0) {
			tot += eval % 10;
			eval /= 10;
		}
		if (mid - tot >= s) {
			r = mid - 1;
			ans = mid;
		}
		else{
			l = mid + 1;
		}
	}
	printf("%llu\n", n - ans + 1);
}
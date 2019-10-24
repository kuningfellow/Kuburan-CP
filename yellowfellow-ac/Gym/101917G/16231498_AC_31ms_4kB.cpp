#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b){
	long long int ret = 1;
	while (ret) {
		ret = a % b;
		a = b;
		b = ret;
	}
	return a;
}
int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		long long int a, b, c, d, e, f;
		scanf("%lld/%lld %lld/%lld %lld/%lld", &a, &b, &c, &d, &e, &f);
		long long int com = b/gcd(b, d)*d;
		com = com/gcd(com, f)*f;
		long long int res = a*(com/b) + c*(com/d) + e*(com/f);
		long long int g = gcd(res, com);
		res /= g;
		com /= g;
		printf("%lld/%lld\n", res, com);
	}
}
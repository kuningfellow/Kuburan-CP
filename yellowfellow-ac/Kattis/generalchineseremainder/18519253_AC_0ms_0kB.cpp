//non coprime Chinese Remainder Theorem
#include<stdio.h>
#include<vector>
using namespace std;
typedef long long int LL;
class solution {
private:
	LL gcd;
	pair<LL, LL> egcd(LL a, LL b) {
		if (b == 0) {
			gcd = a;
			return pair<LL, LL>(1, 0);
		}
		pair<LL, LL> rec = egcd(b, a % b);
		pair<LL, LL> ret;
		ret.first = rec.second;
		ret.second = rec.first - a / b * rec.second;
		return ret;
	}
	LL mod(LL a, LL b) {
		return (a%b + b) % b;
	}
	LL abs(LL a) {
		if (a < 0) return -a;
		return a;
	}
public:
	solution() {
		int tc;
		scanf("%d", &tc);
		while (tc--) {
			LL a, b, n, m;
			scanf("%lld %lld %lld %lld", &a, &n, &b, &m);
			pair<LL, LL>bezout = egcd(n, m);
			if (n == m) {
				if (a == b) printf("%lld %lld\n", a, n);
				else printf("no solution\n");
			}
			else {
				if (abs(a - b) % gcd != 0) printf("no solution\n");
				else {
					LL g = m * n / gcd;
					printf("%lld %lld\n", mod(a + mod(n*mod(bezout.first * ((b-a)/gcd), m/gcd), g), g), g);
					                      // intesting property ca mod cb = c(a mod b)    ^
				}
			}
		}
	}
};

#ifndef L0C4L
int main() {
	solution();
	return 0;
}
#endif
// getnum sendiri, cuma int dan long long, pake template
// #define DIBUG "bug_byte_here"
#ifdef DIBUG
#define DEBUG(x, ...) if (DIBUG[x] == '1') {__VA_ARGS__}
#else
#define DEBUG(...)
#endif
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
typedef long long int LL;
typedef std::pair<int,int> P2I;
typedef std::pair<int,std::pair<int,int> > P3I;
typedef std::pair<std::pair<int,int>,std::pair<int,int> > P4I;
#define PB push_back
#define FI first
#define SE second
template<typename T>void RBIT(T a){a==0?:(RBIT(a>>1),printf("%d", a&1));}

template<typename T>
void getnum(T& var) {
	bool neg = 0;
	char c;
	var = 0;
	while ((c = getchar()) != EOF) {
		if (c == '-' || (c >= '0' && c <= '9')) break;
	}
	if (c == EOF) return;
	else if (c == '-') neg = 1;
	else var = c - '0';
	while ((c = getchar()) != EOF) {
		if (c < '0' || c > '9') break;
		var = var * 10 + (c - '0');
	}
	if (neg) var *= -1;
}

using namespace std;

int main() {
	int n, k, ans = 0;
	scanf("%d %d", &n, &k);
	while (n--) {
		int a;
		getnum(a);
		if (a % k == 0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
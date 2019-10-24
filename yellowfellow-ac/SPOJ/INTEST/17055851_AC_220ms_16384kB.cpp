// scanf int pake getchar sendiri
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
using namespace std;

int scanint() {
	bool neg = 0;
	char c;
	int ret = 0;
	while (1) {
		c = getchar();
		if (c == '-' || (c >= '0' && c <= '9')) break;
	}
	if (c == '-') neg = 1;
	else ret = c - '0';
	while (1) {
		c = getchar();
		if (c < '0' || c > '9') break;
		ret = ret * 10 + c - '0';
	}
	if (neg) return -ret;
	return ret;
}

int main() {
	int n, k, ans = 0;
	scanf("%d %d", &n, &k);
	while (n--) {
		int a = scanint();
		if (a % k == 0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
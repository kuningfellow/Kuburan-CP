// scanf int reference template pake getchar sendiri
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

template<typename T>
void scanum(T& a) {
	bool neg = 0;
	char c;
	a = 0;
	double mul = 1;
	while (1) {
		c = getchar();
		if (c == EOF || c == '-' || c == '.' || (c >= '0' && c <= '9')) break;
	}
	if (c == '-') neg = 1;
	else if (c == '.') mul = 0.1;
	else a = c - '0';
	while (1) {
		c = getchar();
		if (c == '.') mul = 0.1;
		else if (c < '0' || c > '9') break;
		else {
			if (mul < 1) a = a + mul * (c - '0');
			else a = a * 10 + (c - '0');
			if (mul < 1) mul *= 0.1;
		}
	}
	if (neg) a *= -1;
}

int main() {
	int n, k, ans = 0;
	scanf("%d %d", &n, &k);
	while (n--) {
		int a;
		scanum(a);
		if (a % k == 0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
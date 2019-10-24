// coba punya orang beda lagi di CF
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

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int main() {
	int n, k, ans = 0;
	scanf("%d %d", &n, &k);
	while (n--) {
		int a = readInt();
		if (a % k == 0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
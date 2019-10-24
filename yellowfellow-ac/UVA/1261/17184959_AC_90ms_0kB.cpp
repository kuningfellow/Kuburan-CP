//UVA 1261 String Popping
#define BUG ""
#ifdef BUG
#define DEBUG(...) {__VA_ARGS__}
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
template<typename T>void RBIT(T a){if(a>>1)RBIT(a>>1);printf("%d",a&1);}
using namespace std;

int dp[26][26];
char str[26];

int serc(int l, int r) {
	if (l == r) {
		if (str[l] == 'a') return dp[l][r] = 1;
		return dp[l][r] = 2;
	}
	if (dp[l][r] != -1) {
		return dp[l][r];
	}
	dp[l][r] = 0;
	for (int i = l + 1; i <= r; i++) {
		int le = serc(l, i-1);
		int ri = serc(i, r);
		if ((le & 4) && (ri & 4)) dp[l][r] |= 4;
		if ((le & 1) && (ri & 1)) dp[l][r] |= 5;
		if ((le & 2) && (ri & 2)) dp[l][r] |= 6;
		if (le & 4) dp[l][r] |= ri;
		if (ri & 4) dp[l][r] |= le;
	}
	return dp[l][r];
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", str);
		int l = strlen(str);
		for (int i = 0; i < l; i++) {
			for (int j = i; j < l; j++) {
				dp[i][j] = -1;
			}
		}
		if (serc(0, l-1) & 4) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
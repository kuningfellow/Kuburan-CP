#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MOD = 1e9 + 7;

LL dp[550][550];

void pre() {
	dp[1][0] = dp[1][1] = 1;
	for(int i = 2;i <= 500;i++) {
		for(int j = 0;j <= i;j++) {
			if(j == 0) {
				dp[i][j] = (dp[i-1][j] + dp[i-1][j + 1]) % MOD;
			}
			else {
				dp[i][j] = (dp[i - 1][j] + (j) * dp[i-1][j-1] + dp[i-1][j + 1]) % MOD;
			}
		}
	}
}

int main() {
	pre();
	int n;
	cin>>n;
	LL t1 = 0,t2 = 0;
	for(int i = 0;i < n;i++) {
		int x;
		cin>>x;
		if(x == 1) t1++;
		else t2++;
	}
	cout<<dp[n][t2]<<endl;
}
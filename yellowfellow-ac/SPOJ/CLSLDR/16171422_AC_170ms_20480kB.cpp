#include<bits/stdc++.h>
#define PB push_back
#define endl '\n'
using namespace std;

const int N = 1000;
typedef long long LL;
int dp[N + 5][N + 5]; //orang, jump

int calc(int o,int p) {
	if(o == 1) return 1;
	if(dp[o][p] != -1) return dp[o][p];
	return dp[o][p] = ((calc(o - 1,p) + p - 1) % o) + 1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(dp,-1,sizeof dp);
	for(int i = 1;i <= N;i++) for(int j = 1;j <= N;j++) dp[i][j] = calc(i,j);
	int ntc;
	cin>>ntc;
	while(ntc--) {
		int n,m,o;
		cin>>n>>m>>o;
		int res = dp[n][o];
		res -= (n - m);
		while(res <= 0) res += n;
		cout<<res<<endl;
	}
}
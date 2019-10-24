#include <bits/stdc++.h>
using namespace std;
int abss(int a){
	if (a<0)return -a;
	return a;
}
int dp[105][10005];
int pre[105];
int coin[105];
int sav[105];
int n;
int ans;
int serc(int x, int a){
	if (x==n)return 0;
	int ret=(1<<30);
	if (dp[x][a]!=-1){
		return dp[x][a];
	}
	ret=min(ret, max(serc(x+1,a+coin[x]), abss(a+coin[x]-(pre[x]-a)) ) );
	ret=min(ret, max(serc(x+1,a), abss((pre[x+1]-a)-a) ) );
	return dp[x][a]=ret;
}
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		cin>>n;
		ans=0;
		for (int i=0;i<n;i++){
			cin>>coin[i];
			sav[i]=(1<<30);
		}
		for (int i=0;i<=n;i++){
			for (int j=0;j<10005;j++){
				dp[i][j]=-1;
			}
		}
		pre[0]=0;
		for (int i=1;i<=n;i++){
			pre[i]=pre[i-1]+coin[i-1];
		}
		printf ("%d\n",serc(0,0));
	}
}
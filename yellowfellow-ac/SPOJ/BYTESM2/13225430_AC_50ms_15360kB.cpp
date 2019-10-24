#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int ar[105][105];
int n,m;
int serc(int x, int y){
	if (y<0||y==m){
		return -(1<<30);
	}
	if (x==n){
		return 0;
	}
	if (dp[x][y]!=-1)return dp[x][y];
	dp[x][y]=0;
	dp[x][y]=max(dp[x][y],serc(x+1,y+1));
	dp[x][y]=max(dp[x][y],serc(x+1,y-1));
	dp[x][y]=max(dp[x][y],serc(x+1,y));
	dp[x][y]+=ar[x][y];
	return dp[x][y];
}
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		cin>>n>>m;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				cin>>ar[i][j];
				dp[i][j]=-1;
			}
		}
		int ans=0;
		for (int i=0;i<m;i++){
			ans=max(ans,serc(0,i));
		}
		printf ("%d\n",ans);
	}
}
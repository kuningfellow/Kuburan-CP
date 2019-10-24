#include <bits/stdc++.h>
using namespace std;
int ar[25];
int dp[25][1005][2];
int n,N;
int serc(int x, int m){
	if (x==n){
		return m;
	}
	if (dp[x][m][0]!=-1){
		return dp[x][m][0];
	}
	int rem=0;
	int ram=0;
	if (m+ar[x]<=N){
		rem=serc(x+1,m+ar[x]);
	}
	ram=serc(x+1,m);
	if (rem>=ram){
		dp[x][m][0]=rem;
		dp[x][m][1]=m+ar[x];
	}
	else{
		dp[x][m][0]=ram;
		dp[x][m][1]=m;
	}
	return dp[x][m][0];
}
int main(){
	while (scanf("%d%d",&N,&n)!=EOF){
		for (int i=0;i<=n;i++){
			for (int j=0;j<1005;j++){
				dp[i][j][0]=-1;
			}
		}
		for (int i=0;i<n;i++){
			scanf("%d",&ar[i]);
		}
		int sum=serc(0,0);
		int x=0,m=0;
		while (x<n){
			if (dp[x][m][1]!=m){
				printf ("%d ",ar[x]);
			}
			m=dp[x][m][1];
			x++;
		}
		printf ("sum:%d\n",sum);
	}
}
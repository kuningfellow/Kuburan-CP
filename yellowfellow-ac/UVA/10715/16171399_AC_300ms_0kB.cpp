#include<bits/stdc++.h>
using namespace std;
int dp[105][200005];
int bt[105][200005];
int ar[105];
double br[105];
int sum;
int n;
int serc(int x, int c){
	if (x == n){
		return abs(c*2-sum);
	}
	if (dp[x][c]!=-1){
		return dp[x][c];
	}
	int ret = serc(x+1, c);
	int ret2= serc(x+1, c+ar[x]);
	if (ret <= ret2){
		dp[x][c] = ret;
		bt[x][c] = 0;
	}
	else{
		dp[x][c] = ret2;
		bt[x][c] = 1;
	}
	return dp[x][c];
}
int main(){
	while (1){
		scanf("%d",&n);
		if (n == 0)break;
		sum = 0;
		double tsum=0;
		for(int i=0;i<n;i++){
			scanf("%lf",&br[i]);
			tsum+=br[i];
		}
		tsum /= 100;
		for(int i=0;i<n;i++){
			ar[i] = br[i]/tsum*20;
			sum+=ar[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<200005;j++){
				dp[i][j] = -1;
			}
		}
		int ans=serc(0, 0);
		int x = 0;
		int we = 0;
		int fi = 1;
		while (x < n){
			if (bt[x][we] == 1){
				if (!fi)printf(" ");
				printf("%d", x+1);
				fi = 0;
				we+=ar[x];
			}
			x++;
		}
		printf("\n");
	}
}
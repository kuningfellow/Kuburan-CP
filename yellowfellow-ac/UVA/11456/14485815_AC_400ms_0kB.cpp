//UVA 11456 Trainsorting
#include <bits/stdc++.h>
using namespace std;
int dp[2005][2005][2];
int n;
int ar[2005];
int serc(int x, int p, int mode){
	if (x==n)return dp[x][p][mode]=0;
	if (dp[x][p][mode]!=-1){
		return dp[x][p][mode];
	}
	int ret=0;
	if (p==0||(mode==0&&ar[x]>ar[p])||(mode==1&&ar[x]<ar[p])){
		ret=max(ret,1+serc(x+1,x,mode));
	}
	ret=max(ret,serc(x+1,p,mode));
	return dp[x][p][mode]=ret;
}
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		cin>>n;
		n++;
		for (int i=1;i<n;i++){
			scanf("%d",&ar[i]);
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				dp[i][j][0]=dp[i][j][1]=-1;
			}
		}
		serc(1,0,0);
		serc(1,0,1);
		int maxi=0;
		for (int i=1;i<n;i++){
			maxi=max(maxi,dp[i+1][i][0]+dp[i+1][i][1]+1);
		}
		printf ("%d\n",maxi);
	}
}
#include<bits/stdc++.h>
using namespace std;
int dp[200005][8][2];
char rem[200005];
int n;
int serc(int x, int mask, int cut){
	if (x == n){
		if (mask==7){
			return -cut;
		}
		else{
			return 1000000;
		}
	}
	if (dp[x][mask][cut]!=-1){
		return dp[x][mask][cut];
	}
	int ret=serc(x+1,mask,0);
	int misk=mask;
	for (int i=0;i<3&&i+x<n;i++){
		if (rem[x+i]=='R'&&(misk&1)==0){
			misk|=1;
			ret=min(ret, 2-cut+serc(x+i+1,misk,1));
		}
		else if (rem[x+i]=='B'&&(misk&2)==0){
			misk|=2;
			ret=min(ret,2-cut+serc(x+i+1,misk,1));
		}
		else if (rem[x+i]=='G'&&(misk&4)==0){
			misk|=4;
			ret=min(ret,2-cut+serc(x+i+1,misk,1));
		}
		else{
			break;
		}
	}
	return dp[x][mask][cut]=ret;
}
int main(){
	scanf("%s",rem);
	n=strlen(rem);
	for (int i=0;i<n;i++){
		for (int j=0;j<8;j++){
			dp[i][j][0]=dp[i][j][1]=-1;
		}
	}
	printf ("%d\n",serc(0,0,1));
}
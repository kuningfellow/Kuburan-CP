#include <bits/stdc++.h>
using namespace std;
char qr[19][21][22];
int cost[19][19];
int inertial[19];
int n,resc;
int dp[(1<<19)][19][3];
int serc(int mask, int x){
	if (mask==(1<<n)-1){
		return 0;
	}
	if (dp[mask][x][0]!=-1){
		return dp[mask][x][0];
	}
	dp[mask][x][0]=100000;
	for (int i=0;i<n;i++){
		if (mask!=0&&i==x)continue;
		if ((mask&(1<<i))==0){
			int rem=cost[x][i]+serc(mask|(1<<i),i);
			int flag=0;
			if (mask==0){
				rem-=cost[x][i];
				rem+=inertial[i];
			}
			else{
				if (cost[x][i]>inertial[i]+resc){
					rem-=cost[x][i];
					rem+=inertial[i]+resc;
					flag=1;
				}
			}
			if (rem<dp[mask][x][0]){
				dp[mask][x][0]=rem;
				dp[mask][x][1]=i;
				dp[mask][x][2]=flag;
			}
		}
	}
	return dp[mask][x][0];
}
int main(){
	scanf("%d%d",&n,&resc);
	for (int i=0;i<n;i++){
		int cnt=0;
		for (int j=0;j<21;j++){
			scanf("%s",qr[i][j]);
			for (int k=0;k<21;k++){
				if (qr[i][j][k]=='1'){
					cnt++;
				}
			}
		}
		inertial[i]=cnt;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			int tmp=0;
			for (int k=0;k<21;k++){
				for (int l=0;l<21;l++){
					if (qr[i][k][l]!=qr[j][k][l]){
						tmp++;
					}
				}
			}
			cost[i][j]=tmp;
		}
	}
	for (int i=0;i<(1<<n);i++){
		for (int j=0;j<n;j++){
			dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=-1;
		}
	}
	printf ("%d\n",serc(0,0));
	int mask=0,pos=0;
	while (mask!=(1<<n)-1){
		if (dp[mask][pos][2]==1){
			printf ("*\n");
		}
		int sel=dp[mask][pos][1];
		printf("%d\n",sel+1);
		mask|=(1<<sel);
		pos=sel;
	}
}
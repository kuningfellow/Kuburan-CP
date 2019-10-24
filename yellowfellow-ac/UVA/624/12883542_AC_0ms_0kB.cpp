#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	while (scanf("%d",&n)!=EOF){
		cin>>k;
		int ar[k];
		for (int i=0;i<k;i++){
			cin>>ar[i];
		}
		int dp[n+10][2];
		for (int i=0;i<n+10;i++){
			dp[i][0]=0;
			dp[i][1]=-1;
		}
		dp[0][0]=1;
		for (int i=0;i<k;i++){
			for (int j=n;j>=0;j--){
				if (j-ar[i]>=0&&dp[j-ar[i]][0]==1&&dp[j][0]==0){
					dp[j][0]=1;
					dp[j][1]=i;
				}
			}
		}
		int x=n;
		while (dp[x][0]==0){
			x--;
		}
		int res=x;
		vector<int>bac;
		while (x>0){
			bac.push_back(ar[dp[x][1]]);
			x-=ar[dp[x][1]];
		}
		for (int i=bac.size()-1;i>=0;i--){
			printf ("%d ",bac[i]);
		}
		printf ("sum:%d\n",res);
	}
}
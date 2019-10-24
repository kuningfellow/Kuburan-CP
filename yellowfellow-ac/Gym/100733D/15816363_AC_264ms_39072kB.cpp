#include<bits/stdc++.h>
using namespace std;
int dp[1000005];
int ar[1000005];
int n;
int serc(int x){
	if (x>=n){
		return 0;
	}
	if (dp[x]!=-1){
		return dp[x];
	}
	int ret=0;
	ret = serc(x+1);
	ret = max(ret, ar[x]+serc(x+3));
	return dp[x]=ret;
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		scanf("%d",&ar[i]);
	}
	for (int i=0;i<n;i++){
		dp[i]=-1;
	}
	printf ("%d\n",serc(0));
}
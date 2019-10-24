#include <bits/stdc++.h>
using namespace std;
int dp[100005][3];
vector<int>con[100005];
int serc(int x, int stat, int par){
	int ret=0;
	if (dp[x][stat]!=-1){
		return dp[x][stat];
	}
	if (stat==0){
		int temp=1;
		for (int i=0;i<con[x].size();i++){
			if (con[x][i]!=par){
				temp+=serc(con[x][i],1,x);
			}
		}
		ret=max(ret,temp);
		temp=0;
		for (int i=0;i<con[x].size();i++){
			if (con[x][i]!=par){
				temp+=serc(con[x][i],0,x);
			}
		}
		ret=max(ret,temp);
	}
	if (stat==1){
		int temp=0;
		for (int i=0;i<con[x].size();i++){
			if (con[x][i]!=par){
				temp+=serc(con[x][i],0,x);
			}
		}
		ret=max(ret,temp);
	}
	return dp[x][stat]=ret;
}
int main(){
	int n,m;
	cin>>n>>m;
	for (int i=0;i<=n;i++){
		dp[i][0]=dp[i][1]=-1;
	}
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		con[a].push_back(b);
		con[b].push_back(a);
	}
	printf ("%d\n",serc(1,0,1));
}
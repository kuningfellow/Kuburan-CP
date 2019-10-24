#include <bits/stdc++.h>
using namespace std;
vector<int>lis[100005];
int vis[100005];
int targ[100005];
int init[100005];
int sav[100005];
int op;
void dfs(int x, int odd , int even, int lev){
	vis[x]=1;
	if (lev%2==0&&even==1){
		init[x]^=1;
	}
	if (lev%2==1&&odd==1){
		init[x]^=1;
	}
	if (init[x]!=targ[x]){
		sav[x]=1;
		init[x]^=1;
		if (lev%2==0){
			even^=1;
		}
		else odd^=1;
		op++;
	}
	for (int i=0;i<lis[x].size();i++){
		if (vis[lis[x][i]]==0){
			dfs(lis[x][i],odd,even,lev+1);
		}
	}
}
int main(){
	int n;
	cin>>n;
	int a,b;
	for (int i=0;i<n-1;i++){
		cin>>a>>b;
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	for (int i=1;i<=n;i++){
		cin>>init[i];
	}
	for (int i=1;i<=n;i++){
		cin>>targ[i];
	}
	dfs(1,0,0,0);
	printf ("%d\n",op);
	for (int i=1;i<=n;i++){
		if (sav[i]==1){
			printf ("%d\n",i);
		}
	}
}
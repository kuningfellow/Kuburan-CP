#include <bits/stdc++.h>
using namespace std;
int n,k;
int vis[30005];
int go[30005];
void dfs(int x){
	vis[x]=1;
	if (x+go[x]<n&&vis[x+go[x]]==0){
		dfs(x+go[x]);
	}
}
int main(){
	cin>>n>>k;
	k--;
	for (int i=0;i<n-1;i++){
		cin>>go[i];
	}
	dfs(0);
	if (vis[k]==1){
		printf ("YES\n");
	}
	else printf ("NO\n");
}
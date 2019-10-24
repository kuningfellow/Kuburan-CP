#include <bits/stdc++.h>
using namespace std;
int vis[10005];
vector<int>lis[10005];
int n;
int sava,savb;
int dfs(int x, int c){
	vis[x]=1;
	if (c>sava){
		sava=c;
		savb=x;
	}
	int ret=0;
	for (int i=0;i<lis[x].size();i++){
		if (vis[lis[x][i]]==0)
			ret=max(ret,dfs(lis[x][i],c+1));
	}
	return ret+1;
}
int main(){
	cin>>n;
	for (int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	dfs(1,0);
	for (int i=0;i<n;i++){
		vis[i+1]=0;
	}
	printf ("%d\n",dfs(savb,0)-1);
}
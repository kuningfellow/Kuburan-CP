#include <bits/stdc++.h>
using namespace std;
stack<int>ord;
int vis[105];
vector<int>lis[105];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<lis[x].size();i++){
		if (vis[lis[x][i]]==0)
		dfs(lis[x][i]);
	}
	ord.push(x);
}
int main(){
	while (1<2){
		int n,m;
		cin>>n>>m;
		if (n==0&&m==0)break;
		int a,b;
		for (int i=0;i<n;i++){
			vis[i+1]=0;
			lis[i+1].clear();
		}
		for (int i=0;i<m;i++){
			cin>>a>>b;
			lis[a].push_back(b);
		}
		for (int i=1;i<=n;i++){
			if (vis[i]==0){
				dfs(i);
			}
		}
		while (!ord.empty()){
			printf ("%d",ord.top());
			ord.pop();
			if (!ord.empty())printf (" ");
			else printf ("\n");
		}
	}
}
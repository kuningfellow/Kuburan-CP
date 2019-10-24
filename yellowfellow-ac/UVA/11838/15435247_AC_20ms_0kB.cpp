//UVA 11838 Come and Go
#include<bits/stdc++.h>
using namespace std;
const int N=2005;
vector<int>lis[N];
vector<int>lis2[N];
stack<int>st;
int vis[N];
int par[N];
void dfs1(int x){
	vis[x]=1;
	for (int i=0;i<lis[x].size();i++){
		if (vis[lis[x][i]]==0){
			dfs1(lis[x][i]);
		}
	}
	st.push(x);
}
void dfs2(int x, int p){
	par[x]=p;
	vis[x]=1;
	for (int i=0;i<lis2[x].size();i++){
		if (vis[lis2[x][i]]==0){
			dfs2(lis2[x][i],p);
		}
	}
}
int kosaraju(int n){
	for (int i=1;i<=n;i++){
		par[i]=0;
		vis[i]=0;
	}
	for (int i=1;i<=n;i++){
		if (vis[i]==0){
			dfs1(i);
		}
	}
	for (int i=1;i<=n;i++){
		vis[i]=0;
	}
	int idx=1;
	while (!st.empty()){
		if (vis[st.top()]==1){
			st.pop();
			continue;
		}
		dfs2(st.top(),idx++);
	}
	if (idx==2)return 1;
	return 0;
}
int main(){
	int n,m;
	while (scanf("%d%d",&n,&m)&&n>0&&m>0){
		for (int i=1;i<=n;i++){
			lis[i].clear();
			lis2[i].clear();
		}
		for (int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			lis[a].push_back(b);
			lis2[b].push_back(a);
			if (c==2){
				lis[b].push_back(a);
				lis2[a].push_back(b);
			}
		}
		printf ("%d\n",kosaraju(n));
	}
}
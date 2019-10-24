#include <bits/stdc++.h>
using namespace std;
vector<int>lis[300005];
int cost[300005];
int vis[300005];
int dfs1(int x){
	cost[x]=1;
	for (int i=0;i<lis[x].size();i++){
		cost[x]+=dfs1(lis[x][i]);
	}
	return cost[x];
}
stack<int>q;
int dfs2(int x){
	q.push(x);
	for (int i=0;i<lis[x].size();i++){
		dfs2(lis[x][i]);
	}
	while (!q.empty() && cost[x]*2>=cost[q.top()]){
		vis[q.top()]=x;
		q.pop();
	}
}
int main(){
	int n,q,a;
	scanf("%d%d",&n,&q);
	for (int i=2;i<=n;i++){
		scanf("%d",&a);
		lis[a].push_back(i);
	}
	dfs1(1);
	dfs2(1);
	for (int i=0;i<q;i++){
		scanf("%d",&a);
		printf ("%d\n",vis[a]);
	}
}
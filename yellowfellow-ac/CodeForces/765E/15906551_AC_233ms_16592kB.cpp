#include<bits/stdc++.h>
using namespace std;
int vis[200005];
vector<int> lis[200005];
int deg[200005];
int val;
int dfs(int x, int c){
	vis[x]=1;
	int alt=-1;
	int len;
	int leaf=1;
	for (int i = 0; i < lis[x].size(); i++) {
		if (vis[lis[x][i]]==0){
			leaf=0;
			len=dfs(lis[x][i],c+1);
			if (len!=c){
				if (alt==-1){
					alt=len;
				}
				else if (alt!=len){
					val=0;
				}
			}
		}
	}
	int ret=0;
	if (leaf==1)ret=0;
	else if (alt==-1)ret=c;
	else ret = alt;
	return ret+1;
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int a,b;
		scanf("%d%d", &a,&b);
		lis[a].push_back(b);
		lis[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	val=1;
	int res;
	for (int i = n; i > 0; i--) {
		if (deg[i]==1&&vis[i]==0){
			res=dfs(i,0);
		}
	}
	if (val==0)printf("-1\n");
	else{
		while(res!=1&&res%2==1){
			res=(res+1)/2;
		}
		printf("%d\n", res-1);
	}
}
#include<stdio.h>
#include<vector>
using namespace std;
const int maxnode=200005;
const int maxbi=19;
int depth[maxnode];
int logpar[maxnode][maxbi];
vector<int>tree[maxnode];
int cnt[maxnode];
int fin[maxnode];
int mmin(int a, int b){
	return a<b?a:b;
}
int P;
int getbiex(int r, int n){
	return (1<<r) < n ? getbiex(r+1,n):r;
}
void dfs1(int x, int p, int d){
	logpar[x][0]=p;
	depth[x]=d;
	for (int i=0;i<tree[x].size();i++){
		if (tree[x][i]!=p){
			dfs1(tree[x][i],x,d+1);
		}
	}
}
void buildlca(int n){
	P=getbiex(0,n);
	for (int i=1;i<=P;i++){
		for (int j=1;j<=n;j++){
			logpar[j][i]=logpar[logpar[j][i-1]][i-1];
		}
	}
}
int lca(int a, int b){
	if (depth[a]<depth[b]){
		a^=b^=a^=b;
	}
	int dist=depth[a]-depth[b];
	for (int i=0;i<=P;i++){
		if ((dist&(1<<i))>0){
			a=logpar[a][i];
		}
	}
	if (a==b){
		return a;
	}
	for (int i=P;i>=0;i--){
		if (logpar[a][i]!=logpar[b][i]){
			a=logpar[a][i];
			b=logpar[b][i];
		}
	}
	return logpar[a][0];
}
int dfs2(int x, int p){
	int car=0;
	for (int i=0;i<tree[x].size();i++){
		if (tree[x][i]!=p){
			car+=dfs2(tree[x][i],x);
		}
	}
	car+=cnt[x];
	fin[x]+=car;
	return car;
}
int main(){
	int tc;
	int kas=1;
	scanf("%d",&tc);
	while(tc--){
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++){
			tree[i].clear();
			fin[i]=1;
			cnt[i]=0;
		}
		for (int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		dfs1(1,1,0);
		buildlca(n);
		for (int i=n-1;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			int c=lca(a,b);
			cnt[c]-=2;
			cnt[a]++;
			cnt[b]++;
		}
		int ans=200000;
		dfs2(1,1);
		for (int i=2;i<=n;i++){
			ans=mmin(ans,fin[i]);
		}
		printf ("Case #%d: %d\n",kas++,ans);
	}
}
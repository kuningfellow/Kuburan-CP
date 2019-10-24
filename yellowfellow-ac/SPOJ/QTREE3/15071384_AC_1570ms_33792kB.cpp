//HLD QTREE 3 SPOJ
#include<bits/stdc++.h>
using namespace std;
int tree[400005];
int color[100005];
int depth[100005];
int n2t[100005];
int t2n[100005];
int cpar[100005];
int par[100005];
int weight[100005];
vector<int>lis[100005];
int idx;
int comp(int a, int b){
	if (a==-2&&b==-2) return -2;
	else if (a==-2&&b!=-2) return b;
	else if (a!=-2&&b==-2) return a;
	else{
		int ta=depth[a];
		int tb=depth[b];
		if (ta<tb) return a;
		else if (ta>tb) return b;
		else if (ta==tb){
			if (a<b) return a;
			else return b;
		}
	}
}
void update(int l, int r, int k, int q){
	if (l==r){
		if (q==l){
			if (color[l])
				tree[k]=-2;
			else{
				tree[k]=t2n[l];
			}
			color[l]^=1;
		}
		return;
	}
	if (l>q||r<q){
		return;
	}
	update(l,(l+r)/2,k*2,q);
	update((l+r)/2+1,r,k*2+1,q);
	tree[k]=comp(tree[k*2],tree[k*2+1]);
}
int query(int l, int r, int k, int ql, int qr){
	if (ql<=l&&r<=qr){
		return tree[k];
	}
	if (ql>r||qr<l){
		return -2;
	}
	return comp(query(l,(l+r)/2,k*2,ql,qr),query((l+r)/2+1,r,k*2+1,ql,qr));
}
void buildtree(int l, int r, int k){
	if (l==r){
		tree[k]=-2;
		return;
	}
	buildtree(l,(l+r)/2,k*2);
	buildtree((l+r)/2+1,r,k*2+1);
	tree[k]=-2;
}
int dfs1(int x, int p, int d){
	weight[x]=1;
	par[x]=p;
	depth[x]=d;
	for (int i=0;i<lis[x].size();i++){
		if (lis[x][i]!=p){
			weight[x]+=dfs1(lis[x][i],x,d+1);
		}
	}
	return weight[x];
}
void dfs2(int x, int p, int cp){
	cpar[x]=cp;
	n2t[x]=idx;
	t2n[idx++]=x;
	int hld=-1;
	for (int i=0;i<lis[x].size();i++){
		if (lis[x][i]!=p&&(hld==-1||weight[lis[x][i]]>weight[lis[x][hld]])){
			hld=i;
		}
	}
	if (hld!=-1){
		dfs2(lis[x][hld],x,cp);
	}
	for (int i=0;i<lis[x].size();i++){
		if (lis[x][i]!=p&&i!=hld){
			dfs2(lis[x][i],x,lis[x][i]);
		}
	}
}
int hldquery(int a, int n){
	if (cpar[a]==cpar[0]){
		return query(0,n-1,1,n2t[0],n2t[a]);
	}
	return comp(query(0,n-1,1,n2t[cpar[a]],n2t[a]),hldquery(par[cpar[a]],n));
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		lis[a-1].push_back(b-1);
		lis[b-1].push_back(a-1);
	}
	dfs1(0,0,0);
	dfs2(0,0,0);
	buildtree(0,n-1,1);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		if (a==0){
			update(0,n-1,1,n2t[b-1]);
		}
		else{
			printf ("%d\n",hldquery(b-1,n)+1);
		}
	}
}
#include <bits/stdc++.h>
using namespace std;
struct node{
	int weight;
	int pos;
	int par;
	int depth;
	int cpar;
	int cost;
};
typedef node node;
node pts[10005];
int vis[10005];
vector<pair<int,int> >con[10005];
vector<pair<int,int> >lis;
int treemap[10005];
int tree[30005];
int treeidx;
int getord(int n){
	int p=0,mul=1;
	while (mul<n){
		mul*=2;
		p++;
	}
	return p;
}
int dfs1(int x, int p, int d){
	vis[x]=1;
	pts[x].depth=d;
	pts[x].par=p;
	int we=1;
	for (int i=0;i<con[x].size();i++){
		if (vis[con[x][i].first]==0){
			pts[con[x][i].first].cost=con[x][i].second;
			we+=dfs1(con[x][i].first,x,d+1);
		}
	}
	return pts[x].weight=we;
}
void dfs2(int x, int p){
	vis[x]=1;
	treemap[treeidx]=x;
	pts[x].pos=treeidx++;
	pts[x].cpar=p;
	int maxi=0;
	int to=-1;
	for (int i=0;i<con[x].size();i++){
		if (vis[con[x][i].first]==0){
			if (pts[con[x][i].first].weight>maxi){
				maxi=pts[con[x][i].first].weight;
				to=i;
			}
		}
	}
	if (to!=-1){
		dfs2(con[x][to].first,p);
	}
	for (int i=0;i<con[x].size();i++){
		if (vis[con[x][i].first]==0&&i!=to){
			dfs2(con[x][i].first,con[x][i].first);
		}
	}
}
void buildtree(int l, int r, int k){
	if (l==r){
		tree[k]=pts[treemap[l]].cost;
		return;
	}
	buildtree(l,(l+r)/2,k*2);
	buildtree((l+r)/2+1,r,k*2+1);
	tree[k]=max(tree[k*2],tree[k*2+1]);
}
int query(int l, int r, int k, int ql, int qr){
	if (ql<=l&&r<=qr){
		return tree[k];
	}
	if (l>qr||r<ql){
		return 0;
	}
	return max(query(l,(l+r)/2,k*2,ql,qr),query((l+r)/2+1,r,k*2+1,ql,qr));
}
void update(int l, int r, int k, int v, int p){
	if (l==r&&r==p){
		tree[k]=v;
		return;
	}
	if (l>p||r<p){
		return;
	}
	update(l,(l+r)/2,k*2,v,p);
	update((l+r)/2+1,r,k*2+1,v,p);
	tree[k]=max(tree[k*2],tree[k*2+1]);
}
int hldquery(int a, int b, int n){
	if (a==b)return 0;
	if (pts[a].cpar==pts[b].cpar){
		int up=min(pts[a].pos,pts[b].pos);
		int down=max(pts[a].pos,pts[b].pos);
		return query(0,n-1,1,up+1,down);
	}
	else{
		if (pts[pts[a].cpar].depth>=pts[pts[b].cpar].depth){
			return max(query(0,n-1,1,pts[pts[a].cpar].pos,pts[a].pos),hldquery(pts[pts[a].cpar].par,b,n));
		}
		else{
			return max(query(0,n-1,1,pts[pts[b].cpar].pos,pts[b].pos),hldquery(a,pts[pts[b].cpar].par,n));
		}
	}
}
int main(){
	int tc;
	scanf("%d",&tc);
	while (tc--){
		int n;
		scanf("%d",&n);
		int a,b,c;
		treeidx=0;
		lis.clear();
		for (int i=0;i<n;i++){
			con[i].clear();
		}
		for (int i=0;i<n-1;i++){
			scanf("%d%d%d",&a,&b,&c);
			a--;
			b--;
			lis.push_back(pair<int,int>(a,b));
			con[a].push_back(pair<int,int>(b,c));
			con[b].push_back(pair<int,int>(a,c));
		}
		for (int i=0;i<n;i++)
			vis[i]=0;
		dfs1(0,0,0);
		for (int i=0;i<n;i++)
			vis[i]=0;
		dfs2(0,0);
		buildtree(0,n-1,1);
		while (1<2){
			char rem[500];
			scanf("%s",rem);
			if (!strcmp(rem,"DONE"))break;
			if (!strcmp(rem,"QUERY")){
				scanf("%d%d",&a,&b);
				a--;
				b--;
				printf ("%d\n",hldquery(a,b,n));
			}
			else{
				scanf("%d%d",&a,&b);
				a--;
				int edit=-1;
				if (pts[lis[a].first].depth>pts[lis[a].second].depth){
					edit=lis[a].first;
				}
				else{
					edit=lis[a].second;
				}
				update(0,n-1,1,b,pts[edit].pos);
			}
		}
	}
}
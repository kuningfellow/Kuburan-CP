//Heavy-Light Decomposition using log(n) least common ancestor
//SPOJ QTREE2 Query on a Tree II
#include<bits/stdc++.h>
#define MID(x,y) ((x+y)/2)
using namespace std;
int logpar[10005][15];
int depth[10005];
int cpar[10005];
int weight[10005];
vector<pair<int,int> >lis[10005];
int tree[40005];
int n2t[10005];
int t2n[10005];
int cost[10005];
int idx;
int n;
int P;
void getpow(){
	P=0;
	while (1<<P<n)
		P++;
}
void buildlogpar(){
	getpow();
	for (int i=1;i<=P;i++){
		for (int j=0;j<n;j++){
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
	if (a==b)return a;
	for (int i=P;i>=0;i--){
		if (logpar[a][i]!=logpar[b][i]){
			a=logpar[a][i];
			b=logpar[b][i];
		}
	}
	return logpar[a][0];
}
int dfs1(int x, int p, int d){
	logpar[x][0]=p;
	depth[x]=d;
	weight[x]=1;
	for (int i=0;i<lis[x].size();i++){
		if (lis[x][i].first!=p){
			cost[lis[x][i].first]=lis[x][i].second;
			weight[x]+=dfs1(lis[x][i].first,x,d+1);
		}
	}
	return weight[x];
}
void dfs2(int x, int p, int cp){
	n2t[x]=idx;
	t2n[idx]=x;
	idx++;
	cpar[x]=cp;
	int to=-1;
	for (int i=0;i<lis[x].size();i++){
		if (lis[x][i].first!=p&&(to==-1||weight[lis[x][i].first]>weight[lis[x][to].first])){
			to=i;
		}
	}
	if (to!=-1){
		dfs2(lis[x][to].first,x,cp);
	}
	for (int i=0;i<lis[x].size();i++){
		if (lis[x][i].first!=p&&i!=to){
			dfs2(lis[x][i].first,x,lis[x][i].first);
		}
	}
}
void buildtree(int l, int r, int k){
	if (l==r){
		tree[k]=cost[t2n[l]];
		return;
	}
	buildtree(l,MID(l,r),k*2);
	buildtree(MID(l,r)+1,r,k*2+1);
	tree[k]=tree[k*2]+tree[k*2+1];
}
int query(int l, int r, int k, int ql, int qr){
	if (ql<=l&&r<=qr){
		return tree[k];
	}
	else if (ql>r||qr<l){
		return 0;
	}
	return query(l,MID(l,r),k*2,ql,qr)+query(MID(l,r)+1,r,k*2+1,ql,qr);
}
int hldquery(int a, int b){
	if (cpar[a]==cpar[b]){
		return query(0,n-1,1,n2t[b]+1,n2t[a]);
	}
	return query(0,n-1,1,n2t[cpar[a]],n2t[a])+hldquery(logpar[cpar[a]][0],b);
}
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		idx=0;
		cin>>n;
		for(int i=0;i<n;i++){
			lis[i].clear();
		}
		for(int i=1;i<n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			lis[a-1].push_back(pair<int,int>(b-1,c));
			lis[b-1].push_back(pair<int,int>(a-1,c));
		}
		dfs1(0,0,0);
		depth[0]=0;
		dfs2(0,0,0);
		buildlogpar();
		buildtree(0,n-1,1);
		while(1<2){
			char rem[500];
			int a,b;
			scanf("%s",rem);
			if (!strcmp(rem,"DIST")){
				scanf("%d%d",&a,&b);
				a--;
				b--;
				int com=lca(a,b);
				printf ("%d\n",hldquery(a,com)+hldquery(b,com));
			}
			else if (!strcmp(rem,"KTH")){
				int c;
				scanf("%d%d%d",&a,&b,&c);
				a--;
				b--;
				int com=lca(a,b);
				int eval=a;
				int dist=c-1;
				if (depth[a]-depth[com]+1<c){
					c-=(depth[a]-depth[com]+1);
					dist=depth[b]-depth[com]-c;
					eval=b;
				}
				for (int i=P;i>=0;i--){
					if ((dist&(1<<i))>0){
						eval=logpar[eval][i];
					}
				}
				printf ("%d\n",eval+1);
			}
			else{
				break;
			}
		}
		printf ("\n");
	}
}
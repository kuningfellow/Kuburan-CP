#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N = 3e5;
const int INF = 1e9;

pair<LL,LL> ST[4 * N + 5];
int n,m,cnt, col[3*N+5], in[3*N+5], out[3*N+5];
vi adj[3*N+5];


void dfs(int u){
	in[u] = ++cnt;
	for(auto v: adj[u]){
		dfs(v);
	}
	out[u] = cnt;
}

void update(int idx,int l,int r,int tar,int c,int f) {
	if(r < tar || l > tar) return ;
	if(l == tar && tar == r) {
		if(f == 0) ST[idx].FI ^= (1LL<<c);
		else ST[idx].SE ^= (1LL<<c);
		return ;
	}
	int mid = (l + r)/2;
	update(2 * idx,l,mid,tar,c,f), update(2 * idx +1,mid +1,r,tar,c,f);
	ST[idx] = {ST[2 * idx].FI ^ ST[2 * idx + 1].FI,ST[2 * idx].SE ^ ST[2 * idx + 1].SE};
}

pair<LL,LL> query(int idx,int l,int r,int le,int ri) {
	if(r < le || ri < l) return {0,0};
	if(le <= l && r <= ri) return ST[idx];
	int mid = (l + r)/2;
	pair<LL,LL> lhs = query(2 * idx,l,mid,le,ri);
	pair<LL,LL> rhs = query(2 * idx + 1,mid + 1,r,le,ri);
	return {lhs.FI ^ rhs.FI, lhs.SE ^ rhs.SE};
}


int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&col[i]);
	int x;
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		adj[x].pb(i);	
	}
	cnt=0;
	dfs(1);
	
	//build di awal
	for(int i=1;i<=n;i++){
		int c = col[i];
		int fl = 0;
		if(c >= 51) c -= 51, fl = 1;
		update(1,1,n,in[i],c,fl);
	}
	
	int com, node;
	while(m--){
		scanf("%d %d",&com,&node);
		if(com==0){
			pair<LL,LL> res = query(1,1,n,in[node],out[node]);
			int tot = 0;
			while(res.FI){
				if(res.FI & 1) tot++;
				res.FI/=2;
			}
			while(res.SE){
				if(res.SE & 1) tot++;
				res.SE/=2;
			}
			printf("%d\n",tot);
		}
		else{
			int c = col[node];
			int fl = 0;
			if(c >= 51) c -= 51, fl = 1;
			update(1,1,n,in[node],c,fl);
			col[node] = com;
			c = col[node];
			fl = 0;
			if(c >= 51) c -= 51, fl = 1;
			update(1,1,n,in[node],c,fl);
		}
	}
	return 0;
}
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N = 1e5;
const int INF = 1e9;

int n, sink=1002, src=1001;
int cnt[1010], res[1010][1010], cost[1010][1010];
vi adj[1010];
set<int> st;
set<int>::iterator it;
queue<int> q;
int par[1010], dist[1010], C, flow;

void augment(int u, int f){
	if(u==src){
		flow = f;
		return;
	}
	if(par[u]==-1) return;
	augment(par[u], min(f,res[par[u]][u]));
	res[par[u]][u] -= flow;
	res[u][par[u]] += flow;
	C += cost[par[u]][u];
}

bool bellman(){
	for(int i=0;i<1010;i++) dist[i]=INF, par[i]=-1;
	dist[src]=0;
	bool alter;
	for(int i=0;i<n-1;i++){
		alter=false;
		for(int u=1;u<=1002;u++){
			for(auto v: adj[u]){
				if(dist[u]+cost[u][v] < dist[v] && res[u][v]){
					alter=true;
					dist[v] = dist[u] + cost[u][v];
					par[v]=u;
				}
			}
		}
		if(!alter) break;
	}
	return dist[sink]!=INF;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		//reset
		st.clear();
		for(int i=0;i<1010;i++) {
			adj[i].clear();
			cnt[i]=0;
			for(int j=0;j<1010;j++) res[i][j]=0, cost[i][j]=0;
		}
		
		scanf("%d",&n);
		int x;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			cnt[x]++;
			st.insert(x);
		}
		
		for(it=st.begin(); it!=st.end(); it++){
			adj[src].pb(*it);
			res[src][*it] = cnt[*it];
			adj[*it].pb(src);
		}
		for(int i=1;i<=n;i++){
			adj[i].pb(i+500); res[i][i+500]=INF;
			adj[i+500].pb(i); res[i+500][i]=INF;
		}
		for(int i=1;i<=n;i++){
			adj[i+500].pb(sink); res[i+500][sink]=1;
			adj[sink].pb(i+500);
		}
		
		int m,a,b;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			adj[a].pb(b+500); cost[a][b+500]=1; res[a][b+500]=INF;
			adj[b+500].pb(a); cost[b+500][a]=-1;
			
			adj[b].pb(a+500); cost[b][a+500]=1; res[b][a+500]=INF;
			adj[a+500].pb(b); cost[a+500][b]=-1;
		}
		int ans = 0, hitung=0;
		while(bellman()){
			C=0;
			augment(sink,INF);
//			cout<<endl;
//			cout<<"cost = "<<C<<endl;
			hitung +=flow;
			ans+=C;
		}
//		assert(hitung==n);
//		cout<<hitung<<endl;
		printf("%d\n\n",ans);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;


struct edge{
	int nx;
	int cap, cost;
	int backidx;
};

vector<edge> vec[700];
int arr[86][86];

int py[] = {1,0,-1,0};
int px[] = {0,1,0,-1};

void addEdge(int u,int v,int cost) {
	edge tmp,tmp2;
	tmp.nx = v;
	tmp.cost = cost;
	tmp.cap = 1;
	tmp.backidx = vec[v].size();
	tmp2.nx = u;
	tmp2.cost = -cost;
	tmp2.cap = 0;
	tmp2.backidx = vec[u].size();
	vec[u].push_back(tmp);
	vec[v].push_back(tmp2);
}

int id[750];
int dist[750];
int par[750];
int f;

int bellman(int src,int snk) {
	for(int i = src;i <= snk;i++) dist[i] = 1e9;
	dist[src] = 0;
	for(int i = 1; i <= snk + 5;i++) {
		bool ada = false;
		for(int j = src;j <= snk;j++) {
			if(dist[j] == 1e9) continue;
			for(int k = 0;k < vec[j].size();k++) {
				edge nx = vec[j][k];
				if(dist[nx.nx] > dist[j] + nx.cost && nx.cap != 0) {
					dist[nx.nx] = dist[j] + nx.cost;
					par[nx.nx] = j;
					id[nx.nx] = k;
					ada = true;
				}
			}
		}
		if(ada == false) break;
	}
	return dist[snk];
}

void backtrack(int x) {
	if(x == 0) return ;
	int pr = par[x];
	int ie = id[x];
	f = min(f, vec[pr][ie].cap);
	backtrack(pr);
	vec[pr][ie].cap -= f;
	vec[x][vec[pr][ie].backidx].cap += f;
}

int MCMF(int src,int snk) {
	int res = 0;
	while(1) {
		int total = bellman(src,snk);
		if(total > 100000) break;
		res += total;
		f = 1e9;
		backtrack(snk);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m;	
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) cin>>arr[i][j];
	}
	int src = 0, snk = n * m + 1;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if((i + j) % 2 == 0) {
				addEdge(0,(i - 1) * m + j,0);
				for(int k = 0;k < 4;k++) {
					int ii = py[k] + i;
					int jj = px[k] + j;
					if(ii <= 0 || jj <= 0 || ii > n || jj > m) continue;
					addEdge((i - 1) * m + j,(ii - 1) * m + jj,(arr[i][j] == arr[ii][jj])?0:1);
				}
			}
			else {
				addEdge((i - 1) * m + j,snk,0);
			}
		}
	}
	int ct = MCMF(src,snk);
	cout<<ct<<'\n';
}
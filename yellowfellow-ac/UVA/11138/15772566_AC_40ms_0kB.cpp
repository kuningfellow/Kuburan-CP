//UVA 11138 Nuts and Bolts
//Hopcroft Karp algorithm for bipartide matching
#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int fit[N][N];
int match[N * 2];
int col[N * 2];
vector<int>lis[N * 2];
vector<int>nlis[N * 2];
stack<int>eval;
int vis[N * 2];
void bfs(int n){
	queue<int>q;
	for (int i = 0; i < n; i++){
		vis[i] = 0;
		nlis[i].clear();
		if (col[i] == 0 && match[i] == -1){
			q.push(i);
		}
	}
	while( !q.empty() ){
		int siz = q.size();
		for (int i = 0; i < siz; i++){
			int v = q.front();
			q.pop();
			if (vis[v] == 1)continue;
			vis[v] = 1;
			if (col[v] == 1){
				if (match[v] == -1){
					eval.push(v);
				}
				else{
					q.push(match[v]);
					nlis[match[v]].push_back(v);
				}
			}
			else{
				for (int j = 0; j < lis[v].size(); j++){
					if ( vis[ lis[v][j] ] == 0 ){
						q.push( lis[v][j] );
						nlis[lis[v][j]].push_back(v);
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		vis[i] = 0;
	}
}
int dfs(int x){
	vis[x] = 1;
	if (col[x] == 0 && match[x] == -1){
		return 1;
	}
	for (int i = 0 ; i < nlis[x].size(); i++){
		if (vis[ nlis[x][i] ] == 0){
			int ret = dfs(nlis[x][i]);
			if (ret == 1){
				if (col[x] == 1){
					match[nlis[x][i]] = x;
					match[x] = nlis[x][i];
				}
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int tc, kas = 1;
	cin >> tc;
	while ( tc-- ){
		int n, m;
		cin >> n >> m;
		int tot = n + m;
		for (int i = 0; i < tot; i++){
			match[i] = -1;
			col[i] = 0;
			lis[i].clear();
		}
		for (int i = n; i < tot; i++){
			col[i] = 1;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				int a;
				scanf("%d", &a);
				if (a == 1){
					lis[i].push_back(j + n);
					lis[j + n].push_back(i);
				}
			}
		}
		while(1 < 2){
			bfs(tot);
			if (eval.empty()){
				break;
			}
			while( !eval.empty() ){
				if (vis[eval.top()] == 0){
					dfs(eval.top());
				}
				eval.pop();
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			if (match[i] != -1){
				ans++;
			}
		}
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", kas++, ans);
	}
	return 0;
}
// SPOJ MATCHING - Fast Maximum Matching
// experiment with Hopcroft-Karp (using old version)
#include<bits/stdc++.h>
using namespace std;
const int N = 50005;
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
  int n, m, p;
  scanf("%d %d %d", &n, &m, &p);
  for (int i = 0; i < m; i++) {
    col[i + n] = 1;
  }
  for (int i = 0; i < n + m; i++) {
    match[i] = -1;
  }
  while (p--) {
    int a, b;
    scanf("%d %d", &a, &b);
    lis[a-1].push_back(b-1 + n);
  }
  while (1 < 2) {
    bfs(n + m);
    if (eval.empty()) break;
    while (!eval.empty()) {
      if (vis[eval.top()] == 0) dfs(eval.top());
      eval.pop();
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (match[i] != -1) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
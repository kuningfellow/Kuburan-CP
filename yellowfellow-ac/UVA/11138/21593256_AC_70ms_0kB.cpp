// tes CP cheatsheet

#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>
#include<queue>
namespace HopcroftKarp {
  const int maxN = 1005;
  int match[maxN], vis[maxN];
  std::vector<int> lis[maxN];  // "One sided"
  std::vector<int> evalis[maxN];
  void reset(int n) {
    for (int i = 0; i < n; i++) {
      match[i] = -1;
      lis[i].clear();
      evalis[i].clear();
    }
  }
  void addEdge(int l, int r) {
    lis[l].push_back(r);
  }
  int augment(int x) {
    if (vis[x]) return 0;
    vis[x] = 1;
    for (auto to : evalis[x]) {
      if (match[to] == -1 || augment(match[to])) {
        match[to] = x;
        match[x] = to;
        return 1;
      }
    }
    return 0;
  }
  int run(int l, int r) {
    int total = 0;
    while (1 < 2) {
      std::queue<int> q, eval;
      for (int i = 0; i < l + r; i++) {
        vis[i] = 0;
        evalis[i].clear();
      }
      for (int i = 0; i < l; i++)
        if (match[i] == -1) q.push(i);
      while (!q.empty()) {
        int siz = q.size();
        while (siz--) {
          int x = q.front();
          q.pop();
          if (vis[x]) continue;
          vis[x] = 1;
          for (auto to : lis[x]) {
            evalis[to].push_back(x);
            if (match[to] == -1) eval.push(to);
            else q.push(match[to]);
          }
        }
      }
      if (eval.empty()) break;
      for (int i = 0; i < r; i++) {
        vis[i + l] = 0;
      }
      while (!eval.empty()) {
        int x = eval.front();
        eval.pop();
        if (vis[x] == 0) total += augment(x);
      }
    }
    return total;
  }
}

int main(){
  int tc, kas = 1;
  cin >> tc;
  while ( tc-- ){
    int n, m;
    cin >> n >> m;
    HopcroftKarp::reset(n + m);
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        int a;
        scanf("%d", &a);
        if (a == 1){
          HopcroftKarp::addEdge(i, j+n);
        }
      }
    }
    printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", kas++, HopcroftKarp::run(n, m));
  }
  return 0;
}
// SPOJ MATCHING - Fast Maximum Matching
// trying out my template

#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

namespace HopcroftKarp {
  const int maxN = 100001;
  int match[maxN], vis[maxN];
  int total;
  vector<int> lis[maxN];  // "One sided"
  vector<int> evalis[maxN];
  queue<int> eval;
  void reset(int n) {
    total = 0;
    for (int i = 0; i < n; i++) {
      match[i] = -1;
      lis[i].clear();
      evalis[i].clear();
    }
  }
  void addedge(int l, int r) {
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
    while (1 < 2) {
      queue<int> q;
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

int main() {
  int n, m, p;
  scanf("%d %d %d", &n, &m, &p);
  HopcroftKarp::reset(n + m);
  while (p--) {
    int l, r;
    scanf("%d %d", &l, &r);
    HopcroftKarp::addedge(l-1, r-1 + n);
  }
  printf("%d\n", HopcroftKarp::run(n, m));
  return 0;
}
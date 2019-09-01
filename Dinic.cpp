#include<vector>
#include<queue>
#include<algorithm>
namespace DINIC {
  typedef long long int LL;
  const int maxN = 5005;
  struct edge {
    int v, b;
    LL f; // flow
  };
  std::vector<edge>lis[maxN];
  int vis[maxN], st[maxN];
  int n; // number of nodes (0=source,n-1=sink)
  void addEdge(int a, int b, LL f) {
    int ba = lis[b].size();
    int bb = lis[a].size();
    // bidirectional flow
    lis[a].push_back({b, ba, f});
    lis[b].push_back({a, bb, f});
  }
  int bfs() {
    std::queue<int> q;
    for (int i = 0; i < n; i++)
      st[i] = 0, vis[i] = -1;
    vis[0] = 0;
    q.push(0);
    while (!q.empty() && vis[n-1] == -1) {
      int siz = q.size();
      while (siz--) {
        int v = q.front();
        q.pop();
        for (auto e : lis[v]) {
          if (e.f > 0 && vis[e.v] == -1) {
            vis[e.v] = vis[v] + 1;
            q.push(e.v);
          }
        }
      }
    }
    return vis[n-1];
  }
  LL dfs(int x, LL car) {
    if (x == n - 1) {
      return car;
    }
    for (int i = st[x]; i < lis[x].size() && car > 0; i++) {
      edge &e = lis[x][st[x] = i];
      if (e.f > 0 && vis[e.v] == vis[x] + 1) {
        LL ret = dfs(e.v, std::min(car, e.f));
        if (ret > 0) {
          e.f -= ret;
          lis[e.v][e.b].f += ret;
          return ret;
        }
      }
    }
    return 0;
  }
  LL maxflow() {
    LL ans = 0;
    while (1 < 2) {
      int d = bfs();
      if (d == -1) break;
      LL ret;
      while (ret = dfs(0, ~(1ll << 63))) {
        ans += ret;
        if (ret == 0) break;
      }
    }
    return ans;
  }
}
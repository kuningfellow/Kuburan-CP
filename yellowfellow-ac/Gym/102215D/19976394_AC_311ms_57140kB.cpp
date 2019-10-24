#ifdef Kelly
#include<DEBUG.h>
#else
#define DEBUG(...)
#endif
/*-------------------------------<   Kelly   >-------------------------------*/
#include<stdio.h>
#include<vector>

using namespace std;

const int maxN = 200000;
vector<int>adj[maxN];
vector<int>red;
vector<int>blue;
int par[50][maxN];
int depth[maxN];
int P;

void serc(int x, int p, int d) {
  par[0][x] = p;
  depth[x] = d;
  for (auto to : adj[x]) {
    if (to != p) {
      serc(to, x, d + 1);
    }
  }
}

void build(int n) {
  P = 0;
  while ((1 << (P+1)) <= n) {
    P++;
  }
  for (int i = 1; i <= P; i++) {
    for (int j = 0; j < n; j++) {
      par[i][j] = par[i-1][par[i-1][j]];
    }
  }
}

int lca(int a, int b) {
  if (depth[a] < depth[b]) {
    a ^= b ^= a ^= b;
  }
  int del = depth[a] - depth[b];
  for (int i = 0; i <= P; i++) {
    if (del & (1 << i)) {
      a = par[i][a];
    }
  }
  if (a == b) return a;
  for (int i = P; i >= 0; i--) {
    if (par[i][a] != par[i][b]) {
      a = par[i][a];
      b = par[i][b];
    }
  }
  return par[0][a];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }
  serc(0, 0, 1);
  build(n);
  DEBUG("lca of %d %d is %d\n", 1, 3, lca(1, 3));
  int q;
  scanf("%d", &q);
  while (q--) {
    int r, b, x;
    scanf("%d %d", &r, &b);
    int R = -1, B = -1;
    red.clear();
    blue.clear();
    while (r--) {
      scanf("%d", &x);
      x--;
      red.push_back(x);
      if (R == -1) R = x;
      else R = lca(R, x);
    }
    while (b--) {
      scanf("%d", &x);
      x--;
      blue.push_back(x);
      if (B == -1) B = x;
      else B = lca(B, x);
    }
    DEBUG("%d %d\n", R, B);
    int val = 3;
    for (auto c : red) {
      int l = lca(c, B);
      DEBUG("%d to %d is %d\n", c, B, l);
      if (l == B) {
        val &= 2;
        break;
      }
    }
    for (auto c : blue) {
      int l = lca(c, R);
      DEBUG("%d to %d is %d\n", c, R, l);
      if (l == R) {
        val &= 1;
        break;
      }
    }
    if (val != 0) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
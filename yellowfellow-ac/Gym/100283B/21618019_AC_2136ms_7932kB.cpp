#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct dat {
  int idx, nxt, tail;
  long long int inc, dec;
};

vector<pair<long long int,pair<int,int>>>lis;
long long int ans[100005];
int size[100005];
int par[100005];
dat ar[100005];

int finpar(int x) {
  if (par[x] == x) return x;
  return par[x] = finpar(par[x]);
}

int main() {
  freopen("road.in", "r", stdin);
  int tc, kas = 0;
  scanf("%d", &tc);
  while (tc--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
      size[i] = 1;
      ans[i] = 0;
      ar[i].idx = ar[i].tail = i;
      ar[i].inc = ar[i].dec = 0;
      ar[i].nxt = -1;
    }
    lis.clear();
    for (int i = 0; i < m; i++) {
      int a, b;
      long long int c;
      scanf("%d %d %lld", &a, &b, &c);
      lis.push_back(pair<long long int,pair<int,int>>(c, pair<int,int>(a, b)));
    }
    sort(lis.begin(), lis.end());
    int ptr = -1;
    for (int i = 0; i < m; i++) {
      int a = finpar(lis[i].second.first);
      int b = finpar(lis[i].second.second);
      long long int c = lis[i].first;
      if (a != b) {
        par[b] = a;
        int &A = size[a];
        int &B = size[b];
        ar[a].inc += c * B;
        ar[ar[a].tail].dec -= c * B;
        ar[b].inc += c * A;
        ar[ar[b].tail].dec -= c * A;
        ptr = a;
        A += B;
        ar[ar[a].tail].nxt = b;
        ar[a].tail = ar[b].tail;
      }
    }
    long long int inc = 0, dec = 0;
    while (ptr != -1) {
      inc += ar[ptr].inc;
      ans[ar[ptr].idx] += inc + dec;
      dec += ar[ptr].dec;
      ptr = ar[ptr].nxt;
    }
    printf("Case %d:\n", ++kas);
    for (int i = 1; i <= n; i++) {
      printf("%lld\n", ans[i]);
    }
  }
  return 0;
}
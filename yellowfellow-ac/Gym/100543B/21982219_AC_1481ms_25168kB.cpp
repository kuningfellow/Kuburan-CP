#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long int TD;
typedef pair<TD,TD> Pt;
const TD EPS = 0;

vector<Pt> lis;

TD cross(Pt a, Pt b, Pt c) {
  Pt v, u;
  v.first = a.first - c.first;
  v.second = a.second - c.second;
  u.first = b.first - c.first;
  u.second = b.second - c.second;
  return v.first * u.second - v.second * u.first;
}

namespace ST {
  struct dat {
    vector<Pt>hull;
    Pt mid;
  };
  dat node[1 << 18];
  void build(int k, int l, int r) {
    if (l == r) {
      node[k].mid = lis[l];
    } else {
      build(k*2, l, (l+r)/2);
      build(k*2+1, (l+r)/2+1, r);
      node[k].hull.clear();
      for (int i = l; i <= r; i++) {
        while (node[k].hull.size() > 1 && cross(lis[i], node[k].hull[node[k].hull.size() - 1], node[k].hull[node[k].hull.size() - 2]) <= EPS) {
          node[k].hull.pop_back();
        }
        node[k].hull.push_back(lis[i]);
      }
      node[k].mid = lis[(l+r)/2];
    }
  }
  int query(int k, int l, int r, int p, Pt a, Pt b) {
    if (r <= p) {
      return -1;
    } else if (l == r) {
      if (cross(lis[l], b, a) < EPS) {
        return l;
      }
      return -1;
    } else {
      if (p >= (l+r)/2) {
        return query(k*2+1, (l+r)/2+1, r, p, a, b);
      } else {
        int le = 0, ri = node[k].hull.size() - 1;
        while (le + 100 < ri) {
          int m1 = (le*2 + ri) / 3;
          int m2 = (le + ri*2) / 3;
          if (node[k].hull[m1].first <= lis[p].first) {
            le = m1 + 1;
            continue;
          }
          TD c1 = cross(node[k].hull[m1], b, a);
          TD c2 = cross(node[k].hull[m2], b, a);
          if (c1 <= c2) {
            ri = m2;
          } else {
            le = m1;
          }
        }
        TD best = 1, tmp;
        for (int i = le; i <= ri; i++) {
          tmp = cross(node[k].hull[i], b, a);
          if (tmp < best) best = tmp;
        }
        if (best >= 0) return -1;
        int ret = query(k*2, l, (l+r)/2, p, a, b);
        if (ret != -1) return ret;
        return query(k*2+1, (l+r)/2+1, r, p, a, b);
      }
    }
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    lis.clear();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      TD a, b;
      scanf("%lld %lld", &a, &b);
      lis.push_back(Pt(a, b));
    }
    ST::build(1, 0, n-1);
    for (int i = 0; i < n-1; i++) {
      int ans = ST::query(1, 0, n-1, i+1, lis[i], lis[i+1]);
      if (ans == -1) ans = 0;
      if (i) printf(" ");
      printf("%d", ans);
    }
    printf("\n");
  }
  return 0;
}
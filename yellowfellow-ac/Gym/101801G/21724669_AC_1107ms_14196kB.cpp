#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>

typedef long long int LL;

namespace ST {
  struct node {
    LL isi, len, tot;
    LL tot2, isi2;
  };
  node tree[1 << 18];
  LL lazy[2][1 << 18];
  node combine(node le, node ri) {
    node ret;
    ret.len = le.len + ri.len;
    ret.isi = le.isi + ri.isi;
    ret.isi2 = le.isi2 + ri.isi2;
    ret.tot = le.len * ri.isi + le.tot + ri.tot;
    ret.tot2 = ri.len * le.isi2 + le.tot2 + ri.tot2;
    return ret;
  }
  void reset(int k, int l, int r) {
    tree[k].tot = tree[k].tot2 = tree[k].isi = tree[k].isi2 = tree[k].len = lazy[0][k] = lazy[1][k] = 0;
    tree[k].len = r - l + 1;
    if (l != r) {
      reset(k*2, l, (l+r)/2);
      reset(k*2+1, (l+r)/2+1, r);
    }
  }
  void prop(int k, int l, int r) {
    if (lazy[0][k] || lazy[1][k]) {
      tree[k].tot += lazy[0][k] * ((LL)(r-l+1)*(r-l+2)/2);
      tree[k].tot2 += lazy[1][k] * ((LL)(r-l+1)*(r-l+2)/2);
      tree[k].isi += lazy[0][k] * ((LL)(r - l + 1));
      tree[k].isi2 += lazy[1][k] * ((LL)(r - l + 1));
      if (l != r) {
        lazy[0][k*2] += lazy[0][k];
        lazy[0][k*2+1] += lazy[0][k];
        lazy[1][k*2] += lazy[1][k];
        lazy[1][k*2+1] += lazy[1][k];
      }
      lazy[0][k] = lazy[1][k] = 0;
    }
  }
  void update(int k, int l, int r, int ql, int qr, int v, int m = 0) {
    if (ql < 0) return;
    prop(k, l, r);
    if (ql <= l && r <= qr) {
      if (v > 0) lazy[0][k] += v, lazy[1][k] += v;
      else lazy[m][k] += v;
      prop(k, l, r);
    } else if (l > qr || r < ql) {
      return;
    } else {
      update(k*2, l, (l+r)/2, ql, qr, v, m);
      update(k*2+1, (l+r)/2+1, r, ql, qr, v, m);
      tree[k] = combine(tree[k * 2], tree[k * 2 + 1]);
    }
  }
  node query(int k, int l, int r, int ql, int qr) {
    prop(k, l, r);
    if (ql <= l && r <= qr) {
      return tree[k];
    } else if (qr < ql || l > qr || r < ql) {
      return node({0,0,0,0,0});
    } else {
      return combine(query(k*2, l, (l+r)/2, ql, qr), query(k*2+1, (l+r)/2+1, r, ql, qr));
    }
  }
};

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int q;
    scanf("%d", &q);
    ST::reset(1, 1, 100000);
    LL ans = 0;
    while (q--) {
      int type, l, r;
      scanf("%d %d %d", &type, &l, &r);
      if (type == 1) {
        ans += (LL)(r - l + 1) * (r - l + 2) / 2;
        DEBUG(printf("ans now %lld\n", ans);)
        ST::update(1, 1, 100000, l, r, 1);
        ST::update(1, 1, 100000, l-1, l-1, -(r-l + 1), 0);
        ST::update(1, 1, 100000, r+1, r+1, -(r-l + 1), 1);
      } else {
        LL red = ST::query(1, 1, 100000, 1, l-1).tot2 + ST::query(1, 1, 100000, r+1, 100000).tot;
        printf("%lld\n", ans - red);
      }
    }
  }
  return 0;
}
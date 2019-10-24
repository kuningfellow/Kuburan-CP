#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>

typedef long long int LL;

class ST {
  int dir;
public:
  ST (int x) {
    dir = x;
  }
  struct node {
    LL isi, len, last, tot;
  };
  node tree[1 << 18];
  LL lazy[1 << 18];
  node combine(node le, node ri, int l = -1, int r = -1) {
    node ret;
    ret.len = le.len + ri.len;
    ret.isi = le.isi + ri.isi;
    if (dir == 0) {
      ret.tot = le.len * ri.last + le.tot + ri.tot;
      ret.last = ri.last + le.isi;
    } else {
      ret.tot = ri.len * le.last + le.tot + ri.tot;
      ret.last = le.last + ri.isi;
    }
    return ret;
  }
  void reset(int k, int l, int r) {
    tree[k].tot = tree[k].isi = tree[k].last = tree[k].len = lazy[k] = 0;
    tree[k].len = r - l + 1;
    if (l != r) {
      reset(k*2, l, (l+r)/2);
      reset(k*2+1, (l+r)/2+1, r);
    }
  }
  void prop(int k, int l, int r) {
    if (lazy[k]) {
      tree[k].tot += lazy[k] * ((LL)(r-l+1)*(r-l+2)/2);
      tree[k].isi += lazy[k] * ((LL)(r - l + 1));
      tree[k].last += lazy[k] * ((LL)(r - l + 1));
      if (l != r) {
        lazy[k*2] += lazy[k];
        lazy[k*2+1] += lazy[k];
      }
      lazy[k] = 0;
    }
  }
  void update(int k, int l, int r, int ql, int qr, int v) {
    if (ql < 0) return;
    prop(k, l, r);
    if (ql <= l && r <= qr) {
      lazy[k] += v;
      prop(k, l, r);
    } else if (l > qr || r < ql) {
      return;
    } else {
      update(k*2, l, (l+r)/2, ql, qr, v);
      update(k*2+1, (l+r)/2+1, r, ql, qr, v);
      tree[k] = combine(tree[k * 2], tree[k * 2 + 1], l, r);
    }
  }
  node query(int k, int l, int r, int ql, int qr) {
    prop(k, l, r);
    if (ql <= l && r <= qr) {
      return tree[k];
    } else if (qr < ql || l > qr || r < ql) {
      return node({0,0,0,0});
    } else {
      return combine(query(k*2, l, (l+r)/2, ql, qr), query(k*2+1, (l+r)/2+1, r, ql, qr), l, r);
    }
  }
};
//wth
ST LE(1);
ST RI(0);
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int q;
    scanf("%d", &q);
    LE.reset(1, 1, 100000);
    RI.reset(1, 1, 100000);
    LL ans = 0;
    while (q--) {
      int type, l, r;
      scanf("%d %d %d", &type, &l, &r);
      if (type == 1) {
        ans += (LL)(r - l + 1) * (r - l + 2) / 2;
        DEBUG(printf("ans now %lld\n", ans);)
        LE.update(1, 1, 100000, l, r, 1);
        RI.update(1, 1, 100000, l, r, 1);
        RI.update(1, 1, 100000, l-1, l-1, -(r-l + 1));
        LE.update(1, 1, 100000, r+1, r+1, -(r-l + 1));
      } else {
        LL red = LE.query(1, 1, 100000, 1, l-1).tot + RI.query(1, 1, 100000, r+1, 100000).tot;
        printf("%lld\n", ans - red);
      }
    }
  }
  return 0;
}
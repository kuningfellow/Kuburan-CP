#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long int LL;

int ar[100005], le[100005];

namespace ST {
  struct node {
    LL sumW, wH, sumC, maxC;
  };
  node tree[1 << 18];
  LL lazy[1 << 18];
  void reset(int k, int l, int r) {
    tree[k] = {0, 0, 0, 0};
    lazy[k] = 0;
    if (l != r) {
      reset(k*2, l, (l+r)/2);
      reset(k*2+1, (l+r)/2+1, r);
    }
  }
  void prop(int k, int l, int r) {
    if (lazy[k]) {
      tree[k].sumW = lazy[k] * (r-l+1) - tree[k].sumC;
      tree[k].wH = lazy[k];
      if (l != r) {
        lazy[k * 2] = lazy[k];
        lazy[k * 2 + 1] = lazy[k];
      }
      lazy[k] = 0;
    }
  }
  LL update(int k, int l, int r, int p, LL v) {      // returns p's water height
    prop(k, l, r);
    if (l == r) {
      if (l == p) {
        LL ret = tree[k].wH;
        tree[k].sumC += v;
        tree[k].maxC += v;
        tree[k].wH = max(tree[k].wH, tree[k].sumC);   // ceil water height
        tree[k].sumW = tree[k].wH - tree[k].sumC;     // adjust water sum
        return ret;
      }
      return -1;
    } else if (l > p || r < p) {
      return -1;
    } else {
      int le = update(k*2, l, (l+r)/2, p, v);
      int ri = update(k*2+1, (l+r)/2+1, r, p, v);
      tree[k].sumC = tree[k*2].sumC + tree[k*2+1].sumC;
      tree[k].sumW = tree[k*2].sumW + tree[k*2+1].sumW;
      tree[k].maxC = max(tree[k*2].maxC, tree[k*2+1].maxC);
      return max(le, ri);
    }
  }
  LL upgrade(int k, int l, int r, int ql, int qr, LL h) {   // returns delta water sum on ql-qr
    if (ql > qr) {
      return 0;
    }
    prop(k, l, r);
    if (ql <= l && r <= qr) {
      LL old = tree[k].sumW;
      tree[k].sumW = h * (r - l + 1) - tree[k].sumC;
      tree[k].wH = h;
      if (l != r) {
        lazy[k*2] = h;
        lazy[k*2+1] = h;
      }
      return tree[k].sumW - old;
    } else if (l > qr || r < ql) {
      return 0;
    } else {
      LL ret = upgrade(k*2, l, (l+r)/2, ql, qr, h) + upgrade(k*2+1, (l+r)/2+1, r, ql, qr, h);
      tree[k].sumC = tree[k*2].sumC + tree[k*2+1].sumC;
      tree[k].sumW = tree[k*2].sumW + tree[k*2+1].sumW;
      tree[k].maxC = max(tree[k*2].maxC, tree[k*2+1].maxC);
      return ret;
    }
  }
  int findL(int k, int l, int r, int p, int h) {    // h is p's previous water height
    if (l >= p) return -1;                     // returns < position, column height >
    else if (l == r) {
      return l;
    } else {
      if (r < p) {
        if (tree[k*2].maxC <= tree[k*2+1].maxC || tree[k*2+1].maxC > h) return findL(k*2+1, (l+r)/2+1, r, p, h);
        else return findL(k*2, l, (l+r)/2, p, h);
      } else {
        int le = findL(k*2, l, (l+r)/2, p, h), ri = findL(k*2+1, (l+r)/2+1, r, p, h);
        if (le == -1) return ri;
        else if (ri == -1) return le;
        else if (ar[le] > ar[ri] && ar[ri] <= h) return le;
        else return ri;
      }
    }
  }
  int findR(int k, int l, int r, int p, int h) {
    if (r <= p) return -1;
    else if (l == r) {
      return l;
    } else {
      if (l > p) {
        if (tree[k*2].maxC >= tree[k*2+1].maxC || tree[k*2].maxC > h) return findR(k*2, l, (l+r)/2, p, h);
        else return findR(k*2+1, (l+r)/2+1, r, p, h);
      } else {
        int le = findR(k*2, l, (l+r)/2, p, h), ri = findR(k*2+1, (l+r)/2+1, r, p, h);
        if (le == -1) return ri;
        else if (ri == -1) return le;
        else if (ar[le] < ar[ri] && ar[le] <= h) return ri;
        else return le;
      }
    }
  }
}

template<typename T>
void getnum(T& var) {
	bool neg = 0;
	char c;
	var = 0;
	while ((c = getchar()) != EOF) {
		if (c == '-' || (c >= '0' && c <= '9')) break;
	}
	if (c == EOF) return;
	else if (c == '-') neg = 1;
	else var = c - '0';
	while ((c = getchar()) != EOF) {
		if (c < '0' || c > '9') break;
		var = var * 10 + (c - '0');
	}
	if (neg) var *= -1;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, q;
    getnum(n);
    getnum(q);
    ST::reset(1, 0, n-1);
    LL ans = 0;
    for (int i = 0, j = -1, k = -1; i < n; i++) {
      getnum(ar[i]);
      ST::update(1, 0, n-1, i, ar[i]);
      le[i] = k;
      if (j <= ar[i]) j = ar[i], k = i;
    }
    for (int i = n-1, j = -1, k = -1; i >= 0; i--) {
      if (le[i] != -1 && k != -1 && min(ar[le[i]], ar[k]) > ar[i]) {
        LL add = ST::upgrade(1, 0, n-1, i, i, min(ar[le[i]], ar[k]));
        ans += add;
      }
      if (ar[i] >= j) j = ar[i], k = i;
    }
    while (q--) {
      char str[5];
      scanf("%s", str);
      if (str[0] == 'P') {
        printf("%lld\n", ans);
      } else {
        int p, v;
        getnum(p);
        getnum(v);
        p--;
        LL ph = ST::update(1, 0, n-1, p, v);
        ans -= max(min(ph - ar[p], (LL)v), 0ll);
        ar[p] += v;
        if (ar[p] > ph) {
          int le = ST::findL(1, 0, n-1, p, ar[p]);
          int ri = ST::findR(1, 0, n-1, p, ar[p]);
          if (le != -1 && le + 1 <= p - 1) {
            ans += ST::upgrade(1, 0, n-1, le + 1, p - 1, min(ar[p], ar[le]));
          }
          if (ri != -1 && p + 1 <= ri - 1) {
            ans += ST::upgrade(1, 0, n-1, p + 1, ri - 1, min(ar[p], ar[ri]));
          }
        }
      }
    }
  }
  return 0;
}
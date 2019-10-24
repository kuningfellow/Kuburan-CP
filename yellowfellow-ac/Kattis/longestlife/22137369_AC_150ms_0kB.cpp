#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
const double INF = 1000000000000.00;
typedef long long int LL;

namespace ST {
  struct Node {
    double m, c;
    Node *l, *r;
  };
  double cut(double m1, double c1, double m2, double c2) {
    return (c2 - c1) / (m1 - m2);
  }
  Node *newNode(Node *x = NULL) {
    Node *ret = (Node*)malloc(sizeof(Node));
    if (x) ret->m = x->m, ret->c = x->c;
    ret->l = ret->r = NULL;
    return ret;
  }
  void update(Node *k, LL l, LL r, double m, double c) {
    if (l == r) {
      if (l*m + c < l*k->m + k->c) {
        k->m = m;
        k->c = c;
      }
    } else {
      LL mid = (l+r) / 2;
      double cu = cut(k->m, k->c, m, c);
      if (cu > mid) {
        if (m > k->m) {
          swap(k->m, m);
          swap(k->c, c);
        }
        if (!k->r) k->r = newNode(k);
        update(k->r, mid+1, r, m, c);
      } else {
        if (m < k->m) {
          swap(k->m, m);
          swap(k->c, c);
        }
        if (!k->l) k->l = newNode(k);
        update(k->l, l, mid, m, c);
      }
    }
  }
  double query(Node *k, LL l, LL r, LL p) {
    if (k == NULL) return INF;
    if (l == r) {
      return l*k->m + k->c;
    } else if ((l+r)/2 < p) {
      return min(p*k->m + k->c, query(k->r, (l+r)/2+1, r, p));
    } else {
      return min(p*k->m + k->c, query(k->l, l, (l+r)/2, p));
    }
  }
}

int main() {
  double N, C, ans;
  int p;
  scanf("%lf %d %lf", &N, &p, &C);
  ans = N;
  ST::Node *root = ST::newNode();
  root->m = 1;
  root->c = 0;
  for (int i = 0; i < p; i++) {
    LL t;
    double x, y;
    scanf("%lld %lf %lf", &t, &x, &y);
    double m = y / x;
    double c = ST::query(root, 0, 2000000000000, t) + C - m*t;
    ST::update(root, 0, 2000000000000, m, c);
    ans = max(ans, (N-c) / m);
  }
  printf("%.9f\n", ans);
  return 0;
}
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
namespace LICHAO {
  struct Node {
    double m, c;    // Persamaan Garis Lurus y = m*x + c
    Node *l, *r;
  };
  Node *newNode(Node *x = NULL) {
    Node *ret = (Node*)malloc(sizeof(Node));
    if (x) ret->m = x->m, ret->c = x->c;
    ret->l = ret->r = NULL;
    return ret;
  }
  void update(Node *k, LL l, LL r, double m, double c) {
    if (l + 1 >= r) {
      if (l*m + c < l*k->m + k->c) k->m = m, k->c = c;
    } else {
      LL mid = (l+r) / 2;
      double cut = (c - k->c) / (k->m - m);    // cut = titik potong
      if (cut > mid) {        // potong di kanan, harus update kanan
        // segmen sebelah kiri cut lebih optimal dengan PGL(m, c)
        if (m > k->m) swap(k->m, m), swap(k->c, c);
        update( (k->r) ? (k->r) : (k->r = newNode(k)), mid, r, m, c);
      } else {              // potong di kiri, harus update kiri
        // segmen sebelah kanan cut lebih optimal dengan PGL(m, c)
        if (m < k->m) swap(k->m, m), swap(k->c, c);
        update( (k->l) ? (k->l) : (k->l = newNode(k)), l, mid, m, c);
      }
    }
  }
  double query(Node *k, LL l, LL r, LL p) {
    if (k == NULL) return INF;
    if (l == r) return l*k->m + k->c;
    else if (p < (l+r)/2) return min(p*k->m + k->c, query(k->l, l, (l+r)/2, p));
    else return min(p*k->m + k->c, query(k->r, (l+r)/2+1, r, p));
  }
}

int main() {
  double N, C, ans;
  int p;
  scanf("%lf %d %lf", &N, &p, &C);
  ans = N;
  LICHAO::Node *root = LICHAO::newNode();
  root->m = 1;
  root->c = 0;
  for (int i = 0; i < p; i++) {
    LL t;
    double x, y;
    scanf("%lld %lf %lf", &t, &x, &y);
    double m = y / x;
    double c = LICHAO::query(root, 0, 1000000000000, t) + C - m*t;
    LICHAO::update(root, 0, 1000000000000, m, c);
    ans = max(ans, (N-c) / m);
  }
  printf("%.9f\n", ans);
  return 0;
}
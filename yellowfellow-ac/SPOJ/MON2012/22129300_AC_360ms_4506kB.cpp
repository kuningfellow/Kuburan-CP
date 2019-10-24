#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<stdlib.h>
#include<utility>
#include<algorithm>

using namespace std;

namespace ST {
  struct Node {
    int val;
    Node *l, *r;
  };
  Node *newNode() {
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->val = 0;
    ret->l = ret->r = NULL;
    return ret;
  }
  int getCont(Node *x) {
    return x == 0 ? 0 : x->val;
  }
  Node* update(Node *cur, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
      if (cur == NULL) cur = newNode();
      cur->val = r - l + 1;
      return cur;
    } else if (l > qr || r < ql) {
      if (cur == NULL) cur = newNode();
      return cur;
    } else {
      if (cur == NULL) cur = newNode();
      if (cur->val == r-l+1) return cur;
      cur->l = update(cur->l, l, (l+r)/2, ql, qr);
      cur->r = update(cur->r, (l+r)/2+1, r, ql, qr);
      cur->val = getCont(cur->l) + getCont(cur->r);
      return cur;
    }
  }
  int query(Node *cur, int l, int r, int ql, int qr) {
    if (cur == NULL) return 0;
    if (ql <= l && r <= qr) {
      return cur->val;
    } else if (l > qr || r < ql) {
      return 0;
    } else {
      if (cur->val == r-l+1) return min(r, qr) - max(l, ql) + 1;
      return query(cur->l, l, (l+r)/2, ql, qr) + query(cur->r, (l+r)/2+1, r, ql, qr);
    }
  }
}

int main() {
  ST::Node *root = NULL;
  int n, c = 0;
  scanf("%d", &n);
  while (n--) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    if (t == 1) {
      c = ST::query(root, 1, 1000000000, x + c, y + c);
      printf("%d\n", c);
    } else {
      root = ST::update(root, 1, 1000000000, x + c, y + c);
    }
  }
  return 0;
}
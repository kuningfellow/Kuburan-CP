#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<utility>

using namespace std;

typedef char T;
namespace TREAP {
  struct Node {
    T val;
    int rnd, size;
    Node *l, *r;
    Node(T _val) {
      val = _val;
      rnd = rand();
      size = 1;
      l = r = NULL;
    }
  };
  typedef pair<int,Node*> PTQ;
  int getSize(Node *x) {
    return x == 0 ? 0 : x->size;
  }
  T getKth(Node *cur, int kth) {
    if (cur == NULL) return -1;
    if (getSize(cur->l) + 1 == kth) return cur->val;
    if (getSize(cur->l) + 1 < kth) {
      return getKth(cur->r, kth - getSize(cur->l) - 1);
    } else {
      return getKth(cur->l, kth);
    }
  }
  PTQ find(Node *cur, T val) {
    if (cur == NULL) return PTQ(0, cur);
    if (cur->val == val) return PTQ(getSize(cur->l) + 1, cur);
    if (cur->val < val) {
      PTQ ret = find(cur->r, val);
      ret.first += 1 + getSize(cur->l);
      return ret;
    } else {
      return find(cur->l, val);
    }
  }
  Node* merge(Node *L, Node *R) {
    if (!L) return R;
    if (!R) return L;
    if (L->rnd < R->rnd) {
      L->r = merge(L->r, R);
      L->size = getSize(L->l) + 1 + getSize(L->r);
      return L;
    } else {
      R->l = merge(L, R->l);
      R->size = getSize(R->l) + 1 + getSize(R->r);
      return R;
    }
  }
  pair<Node*,Node*> split(Node *v, int k) {
    if (v == NULL) return pair<Node*,Node*>(NULL,NULL);
    pair<Node*,Node*> ret;
    if (getSize(v->l) + 1 < k) {
      ret = split(v->r, k - getSize(v->l) - 1);
      v->r = ret.first;
      ret.first = v;
    } else {
      ret = split(v->l, k);
      v->l = ret.second;
      ret.second = v;
    }
    v->size = getSize(v->l) + 1 + getSize(v->r);
    return ret;
  }
  Node* add(Node *cur, int k, T v) {
    if (cur == NULL) return new Node(v);
    pair<Node*,Node*> parts = split(cur, k+1);
    parts.first = merge(parts.first, new Node(v));
    return merge(parts.first, parts.second);
  }
  pair<Node*,Node*> reverse(Node *cur, Node *rev, int l, int r, int l2, int r2) {

    pair<Node*,Node*> ri = split(cur, r+1);
    pair<Node*,Node*> le = split(ri.first, l);

    pair<Node*,Node*> ri2 = split(rev, r2+1);
    pair<Node*,Node*> le2 = split(ri2.first, l2);

    cur = merge(le.first, le2.second);
    cur = merge(cur, ri.second);

    rev = merge(le2.first, le.second);
    rev = merge(rev, ri2.second);

    return pair<Node*,Node*>(cur, rev);
  }
  void trav(Node *x) {
    if (!x) return;
    trav(x->l);
    printf("%c", x->val);
    trav(x->r);
  }
}

TREAP::Node *root = NULL;
TREAP::Node *root2 = NULL;
char str[100005];

int main() {
  srand(time(NULL));
  int n, l, r, m;
  scanf("%d %d %d", &n, &l, &r);
  scanf("%s", str);
  for (int i = 0; i < n; i++) {
    root = TREAP::add(root, i, str[i]);
    root2 = TREAP::add(root2, 0, str[i]);
  }
  scanf("%d", &m);
  while (m--) {
    char A[5], B[5];
    scanf("%s", str);
    if (str[0] == 'Q') {
      scanf("%s", A);
      printf("%c", TREAP::getKth(root, A[0] == 'L' ? l : r));
    } else if (str[0] == 'S') {
      scanf("%s %s", A, B);
      if (A[0] == 'L') {
        if (B[0] == 'L') l--;
        else l++;
      } else {
        if (B[0] == 'L') r--;
        else r++;
      }
    } else {
      pair<TREAP::Node*, TREAP::Node*> ret = TREAP::reverse(root, root2, l, r, n-r+1, n-l+1);
      root = ret.first;
      root2 = ret.second;
    }
  }
  printf("\n");
  return 0;
}

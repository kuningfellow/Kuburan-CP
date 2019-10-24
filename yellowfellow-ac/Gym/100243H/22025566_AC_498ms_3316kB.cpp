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

typedef int T;
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
  void trav(Node *x, int *stat) {
    if (!x) return;
    trav(x->l, stat);
    if (*stat) printf(" ");
    printf("%d", x->val);
    *stat = 1;
    trav(x->r, stat);
  }
  Node* moveToFront(Node *cur, int l, int r) {
    pair<Node*,Node*> ri = split(cur, r+1);
    pair<Node*,Node*> le = split(ri.first, l);
    cur = merge(le.first, ri.second);
    cur = merge(le.second, cur);
    return cur;
  }
}

TREAP::Node *root = NULL;

int main() {
  freopen("movetofront.in", "r", stdin);
  freopen("movetofront.out", "w", stdout);
  srand(time(NULL));
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    root = TREAP::add(root, i+1, i+1);
  }
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    root = TREAP::moveToFront(root, l, r);
  }
  int stat = 0;
  trav(root, &stat);
  printf("\n");
  return 0;
}
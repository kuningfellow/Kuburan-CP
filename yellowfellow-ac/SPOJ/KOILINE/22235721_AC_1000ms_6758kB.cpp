#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<algorithm>
#include<utility>
#include<vector>
#include<stdlib.h>
#include<time.h>

using namespace std;

namespace TREAP {
  struct Node {
    int val, rnd, size;
    Node *l, *r;
  };
  Node *newNode(int val) {
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->l = ret->r = NULL;
    ret->size = 1;
    ret->rnd = rand();
    ret->val = val;
    return ret;
  }
  int getSize(Node *x) {
    return x ? x->size : 0;
  }
  int find(Node *x, int val) {
    if (!x) return 0;
    if (x->val <= val) {
      return getSize(x->l) + 1 + find(x->r, val);
    } else {
      return find(x->l, val);
    }
  }
  int getKth(Node *x, int kth) {
    if (!x) return -1;
    if (getSize(x->l) + 1 == kth) {
      return x->val;
    } else if (getSize(x->l) + 1 < kth) {
      return getKth(x->r, kth - getSize(x->l) - 1);
    } else {
      return getKth(x->l, kth);
    }
  }
  Node *merge(Node *L, Node *R) {
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
  pair<Node*,Node*> split(Node *x, int kth) {
    if (!x) return pair<Node*,Node*>(x, x);
    pair<Node*,Node*> ret;
    if (getSize(x->l) + 1 < kth) {
      ret = split(x->r, kth - getSize(x->l) - 1);
      x->r = ret.first;
      ret.first = x;
    } else {
      ret = split(x->l, kth);
      x->l = ret.second;
      ret.second = x;
    }
    x->size = getSize(x->l) + 1 + getSize(x->r);
    return ret;
  }
  Node *add(Node *x, int val) {
    if (!x) return newNode(val);
    else {
      int k = find(x, val);
      pair<Node*,Node*> parts = split(x, k+1);
      parts.first = merge(parts.first, newNode(val));
      return merge(parts.first, parts.second);
    }
  }
  Node *remove(Node* x, int kth) {
    pair<Node*,Node*> ri = split(x, kth+1);
    pair<Node*,Node*> le = split(ri.first, kth);
    free(le.second);
    return merge(le.first, ri.second);
  }
}

int ar[100005];

int main() {
  TREAP::Node *root = NULL;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    root = TREAP::add(root, x);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &ar[i]);
  }
  for (int i = n-1; i >= 0; i--) {
    int x = TREAP::getKth(root, ar[i] + 1);
    root = TREAP::remove(root, ar[i] + 1);
    ar[i] = x;
  }
  for (int i = 0; i < n; i++) {
    printf("%d\n", ar[i]);
  }
  return 0;
}

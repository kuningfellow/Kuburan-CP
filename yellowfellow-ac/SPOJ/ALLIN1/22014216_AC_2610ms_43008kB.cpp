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
  Node* add(Node *cur, T v) {
    if (cur == NULL) return new Node(v);
    PTQ chk = find(cur, v);
    pair<Node*,Node*> parts = split(cur, chk.first + 1);
    parts.first = merge(parts.first, new Node(v));
    return merge(parts.first, parts.second);
  }
  Node* remove(Node *cur, T v) {
    if (cur == NULL) return NULL;
    PTQ chk = find(cur, v);
    if (chk.second != NULL) {
      pair<Node*,Node*> ri = split(cur, chk.first + 1);
      pair<Node*,Node*> le = split(ri.first, chk.first);
      delete le.second;
      cur = merge(le.first, ri.second);
    }
    return cur;
  }
}

TREAP::Node *root = NULL;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(NULL));
  while (1 < 2) {
    int t, n;
    cin >> t;
    if (t == -1) break;
    cin >> n;
    if (t == 1) root = TREAP::add(root, n);
    else if (t == 2) root = TREAP::remove(root, n);
    else if (t == 3) {
      TREAP::PTQ ret = find(root, n);
      if (ret.second != NULL) printf("%d\n", ret.first);
      else printf("-1\n");
    }
    else if (t == 4) printf("%d\n", TREAP::getKth(root, n));
  }
  return 0;
}
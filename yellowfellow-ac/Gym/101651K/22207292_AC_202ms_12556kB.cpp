#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<utility>

using namespace std;

const int INF = 1000000;
namespace TREAP {
  struct Node {
    bool empty;
    int val, rnd;
    int firstEmpty;
    int size;
    Node *l, *r;
    void update() {
      size = 1;
      if (empty) firstEmpty = 1;
      else firstEmpty = INF;
      int buf = 0;
      if (l) {
        buf = l->size;
        firstEmpty = min(buf + firstEmpty, l->firstEmpty);
        size += l->size;
      }
      if (r) {
        firstEmpty = min(firstEmpty, buf + 1 + r->firstEmpty);
        size += r->size;
      }
    }
  };
  Node *newNode(int val, bool empty = 0) {
    Node *ret = (Node*)malloc(sizeof(Node));
    if (empty) ret->firstEmpty = 1;
    else ret->firstEmpty = INF;
    ret->empty = empty;
    ret->val = val;
    ret->rnd = rand();
    ret->l = ret->r = NULL;
    ret->size = 1;
    return ret;
  }
  int getSize(Node *x) {
    return x ? x->size : 0;
  }
  int getFirstEmpty(Node *x, int l, int r) {
    if (r <= 0) return INF;
    if (!x) return INF;
    if (x->firstEmpty == INF) return INF;
    if (getSize(x) < l) return INF;
    if (l <= x->firstEmpty && x->firstEmpty <= r) {
      return x->firstEmpty;
    } else {
      int le = getSize(x->l);
      int ret = INF;
      if (x->empty && le + 1 >= l && le + 1 <= r) ret = le + 1;
      return min(ret, min(getFirstEmpty(x->l, l, r), le + 1 + getFirstEmpty(x->r, l-le-1, r-le-1)));
    }
  }
  Node *merge(Node *L, Node *R) {
    if (!L) return R;
    if (!R) return L;
    if (L->rnd < R->rnd) {
      L->r = merge(L->r, R);
      L->update();
      return L;
    } else {
      R->l = merge(L, R->l);
      R->update();
      return R;
    }
  }
  pair<Node*,Node*> split(Node *x, int kth) {
    if (!x) return pair<Node*,Node*>(NULL,NULL);
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
    x->update();
    return ret;
  }
  void print(Node *x, int idx, vector<int> &res, int &maxN) {
    if (!x) return;
    print(x->l, idx, res, maxN);
    if (x->empty) {
      res.push_back(0);
    } else {
      maxN = max(maxN, getSize(x->l) + idx + 1);
      res.push_back(x->val);
    }
    print(x->r, idx + getSize(x->l) + 1, res, maxN);
  }
  Node *add(Node *x, int key, int val, bool empty = 0) {
    if (empty) {
      return merge(x, newNode(val, empty));
    } else {
      int kth = getFirstEmpty(x, key, INF);
      if (kth != INF) {
        pair<Node*,Node*> ri = split(x, kth+1);
        pair<Node*,Node*> le = split(ri.first, kth);
        free(le.second);
        x = merge(le.first, ri.second);
      }
      pair<Node*,Node*> parts = split(x, key);
      parts.first = merge(parts.first, newNode(val));
      x = merge(parts.first, parts.second);
      x->update();
      return x;
    }
  }
}

int main() {
  freopen("key.in", "r", stdin);
  freopen("key.out", "w", stdout);
  int n, m;
  scanf("%d %d", &n, &m);
  TREAP::Node *root = NULL;
  for (int i = 0; i < m; i++) {
    root = TREAP::add(root, 0, 0, 1);
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    root = TREAP::add(root, x, i+1);
  }
  int maxN = 0;
  vector<int>ans;
  print(root, 0, ans, maxN);
  printf("%d\n", maxN);
  for (int i = 0; i < maxN; i++) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}

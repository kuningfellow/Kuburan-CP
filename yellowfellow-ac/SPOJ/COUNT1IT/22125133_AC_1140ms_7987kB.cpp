#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<utility>

using namespace std;

typedef int TD;
namespace TREAP {
  struct Node {
    TD val;
    Node *l, *r;
    int rnd, size;
  };
  Node *newNode(TD x) {
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->val = x;
    ret->rnd = rand();
    ret->l = ret->r = NULL;
    ret->size = 1;
    return ret;
  }
  int getSize(Node *x) {
    return x == NULL ? 0 : x->size;
  }
  TD getKth(Node *cur, int kth) {
    if (cur == NULL) return -1;
    if (getSize(cur->l) + 1 == kth) return cur->val;
    else if (getSize(cur->l) + 1 < kth) return getKth(cur->r, kth - getSize(cur->l) - 1);
    else return getKth(cur->l, kth);
  }
  pair<int,Node*> find(Node *cur, TD val) {
    if (cur == NULL) return pair<int,Node*>(0, cur);
    if (cur->val == val) {
      pair<int,Node*> chk = find(cur->l, val);
      if (chk.second != NULL) return chk;
      return pair<int,Node*> (getSize(cur->l) + 1, cur);
    } else if (cur->val < val) {
      pair<int,Node*> chk = find(cur->r, val);
      chk.first += 1 + getSize(cur->l);
      return chk;
    } else {
      return find(cur->l, val);
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
  pair<Node*,Node*> split(Node *cur, int kth) {
    if (!cur) return pair<Node*,Node*>(NULL,NULL);
    pair<Node*,Node*> ret;
    if (getSize(cur->l) + 1 < kth) {
      ret = split(cur->r, kth - getSize(cur->l) - 1);
      cur->r = ret.first;
      ret.first = cur;
    } else {
      ret = split(cur->l, kth);
      cur->l = ret.second;
      ret.second = cur;
    }
    cur->size = getSize(cur->l) + 1 + getSize(cur->r);
    return ret;
  }
  void print(Node *x) {
    if (!x) return;
    print(x->l);
    printf("%d ", x->val);
    print(x->r);
  }
  Node *add(Node *cur, TD val) {
    pair<int,Node*> kth = find(cur, val);
    pair<Node*,Node*> parts = split(cur, kth.first + 1);
    parts.second = merge(newNode(val), parts.second);
    cur = merge(parts.first, parts.second);
    return cur;
  }
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  TREAP::Node* root = NULL;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    root = TREAP::add(root, x);
  }
  while (q--) {
    int t, x;
    scanf("%d %d", &t, &x);
    if (t == 1) {
      int n;
      pair<int,TREAP::Node*> ret = TREAP::find(root, x+1);
      n = ret.first;
      if (ret.second && ret.second->val == x+1) n--;
      root = TREAP::add(root, n + x);
    } else if (t == 2) {
      pair<int,TREAP::Node*> ret = TREAP::find(root, x+1);
      int n = ret.first;
      if (ret.second && ret.second->val == x + 1) n--;
      printf("%d\n", n);
    } else {
      int n = TREAP::getKth(root, x);
      if (n == -1) printf("invalid\n");
      else printf("%d\n", n);
    }
  }
  return 0;
}
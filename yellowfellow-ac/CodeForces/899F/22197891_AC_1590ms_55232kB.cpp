#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<utility>

using namespace std;

const int INF = 1000000000;

namespace TREAP {
  int toInt(char x) {
    if (x >= 'a' && x <= 'z') return x - 'a';
    else if (x >= 'A' && x <= 'Z') return x - 'A' + 26;
    return x - '0' + 52;
  }
  struct Node {
    char c;
    int rnd, size;
    int fir[62];
    Node *l, *r;
    int getfir(char x) {
      return fir[toInt(x)];
    }
    void update() {
      size = 1;
      if (l) size += l->size;
      if (r) size += r->size;
      int buf = 0;
      if (l)
        buf = l->size;
      for (int i = 0; i < 62; i++)
        fir[i] = INF;
      fir[toInt(c)] = buf + 1;
      if (l)
        for (int i = 0; i < 62; i++)
          fir[i] = min(fir[i], l->fir[i]); 
      if (r)
        for (int i = 0; i < 62; i++)
          fir[i] = min(fir[i], r->fir[i] + buf + 1);
    }
  };
  Node *newNode(char x = 0) {
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->l = ret->r = NULL;
    ret->rnd = rand();
    ret->c = x;
    ret->update();
    return ret;
  }
  int getSize(Node *x) {
    return x ? x->size : 0;
  }
  int getRange(Node *cur, int l, int r, char c) {
    if (r <= 0) return INF;
    if (!cur) return INF;
    if (cur->getfir(c) == INF) return INF;
    if (getSize(cur) < l) return INF;
    int le = getSize(cur->l);
    if (l <= cur->getfir(c) && cur->getfir(c) <= r) {
      return cur->getfir(c);
    }
    int ret = INF;
    if (cur->c == c && le + 1 >= l && le + 1 <= r) ret = le + 1;
    return min(ret, min(getRange(cur->l, l, r, c), le + 1 + getRange(cur->r, l-le-1, r-le-1, c)));
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
    x->update();
    return ret;
  }
  void print(Node *x) {
    if (!x) return;
    print(x->l);
    printf("%c", x->c);
    print(x->r);
  }
  Node *addNode(Node *x, char c) {
    return merge(x, newNode(c));
  }
  Node *remove(Node *x, int kth) {
    pair<Node*,Node*> ri = split(x, kth+1);
    pair<Node*,Node*> le = split(ri.first, kth);
    free(le.second);
    x = merge(le.first, ri.second);
    return x;
  }
}

char str[200005];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", str);
  TREAP::Node *root = NULL;
  for (int i = 0; str[i] != '\0'; i++) {
    root = TREAP::addNode(root, str[i]);
  }
  while (m--) {
    int l, r;
    char s[3];
    scanf("%d %d %s", &l, &r, s);
    int k = INF;
    do {
      k = TREAP::getRange(root, l, r, s[0]);
      root = TREAP::remove(root, k);
      r--;
    } while (k != INF && l <= r);
  }
  print(root);printf("\n");
}
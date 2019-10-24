#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

vector<string> dict;

namespace TRIE {
  struct node {
    int cnt;
    node *nxt[26];
  };
  node *newNode() {
    node *ret = (node*)malloc(sizeof(node));
    ret->cnt = 0;
    for (int i = 0; i < 26; i++) ret->nxt[i] = NULL;
    return ret;
  }
  node *add(node *last, string &str) {
    node *ret = newNode();
    node *cur = ret;
    if (last) cur->cnt = last->cnt + 1;
    else cur->cnt = 1;
    for (int i = str.length()-1; i >= -1; i--) {
      if (last) {
        for (int j = 0; j < 26; j++) {
          cur->nxt[j] = last->nxt[j];
        }
      }
      if (i == -1) break;
      cur->nxt[str[i] - 'a'] = newNode();
      cur = cur->nxt[str[i] - 'a'];
      if (last) last = last->nxt[str[i] - 'a'];
      if (last) cur->cnt = last->cnt + 1;
      else cur->cnt = 1;
    }
    return ret;
  }
  int chk(node *ver, node *ver2, string &str) {
    node *cur = ver, *cur2 = ver2;
    for (int i = str.length()-1; i >= 0 && (cur || cur2); i--) {
      if (cur) cur = cur->nxt[str[i] - 'a'];
      if (cur2) cur2 = cur2->nxt[str[i] - 'a'];
    }
    int ret = 0;
    if (cur) ret += cur->cnt;
    if (cur2) ret -= cur2->cnt;
    return ret;
  }
}
TRIE::node *ver[100005];
int substr(string &S, string &s) {
  int l = min(s.length(), S.length());
  int ret = 0;
  for (int i = 0; i < l && !ret; i++) {
    if (S[i] > s[i]) ret |= 1;
    else if (S[i] < s[i]) ret |= 2;
  }
  if (ret == 0) {
    if (s.length() < S.length()) ret |= 1;
    else if (s.length() > S.length()) ret |= 2;
    if (s.length() <= S.length()) ret |= 4;
  }
  return ret;
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    dict.push_back(x);
  }
  sort(dict.begin(), dict.end());
  ver[0] = NULL;
  for (int i = 0; i < n; i++) {
    ver[i+1] = TRIE::add(ver[i], dict[i]);
  }
  while (q--) {
    string pre, suf;
    cin >> pre >> suf;
    int L = n, R = -1;
    int l = 0, r = n-1;
    while (l <= r) {
      int mid = (l + r) / 2;
      int val = substr(dict[mid], pre);
      if (val & 5) {
        if (val & 4) L = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    l = 0, r = n-1;
    while (l <= r) {
      int mid = (l + r) / 2;
      int val = substr(dict[mid], pre);
      if (val & 6) {
        if (val & 4) R = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    int ans = 0;
    if (L <= R) {
      ans = TRIE::chk(ver[R+1], ver[L], suf);
    }
    printf("%d\n", ans);
  }
  return 0;
}
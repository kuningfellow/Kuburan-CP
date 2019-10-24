// test notebook

#include<stdio.h>
#include<string.h>
#include<queue>
char STR[100005];
char str[1005][1005];
int ar[1005];
int ans[1005];
namespace AHOC {
  const int size = 1000005;
  const int sigma = 52;
  int nxt[size][sigma];
  int mark[size], kmp[size], sl[size];
  int gptr;
  // zero-based char to int mapper
  int to(const char x)
  {
    if (x >= 'a' && x <= 'z') return x - 'a';
    return x - 'A' + 26;
  }
  void reset() {
    gptr = 0;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < sigma; j++) nxt[i][j] = -1;
      mark[i] = kmp[i] = sl[i] = 0;
    }
  }
  void add(const char *str, int x) {
    int ptr = 0, i = 0;
    while (str[i] != '\0') {
      // str: string pattern
      int t = to(str[i]);
      if (nxt[ptr][t] == -1)
        nxt[ptr][t] = ++gptr;
      ptr = nxt[ptr][t];
      i++;
    }
    // mark[ptr] = x;  // x-th string (1 based)
    if (mark[ptr] != 0) ar[x] = mark[ptr];
    else mark[ptr] = x + 1, ar[x] = x + 1;
  }
  void build() {
    std::queue<int>q;
    for (int i = 0; i < sigma; i++) {
      if (nxt[0][i] != -1) q.push(nxt[0][i]);
    }
    while (!q.empty()) {
      int siz = q.size();
      for (int i = 0; i < siz; i++) {
        int v = q.front();
        q.pop();
        for (int j = 0; j < sigma; j++) {
          if (nxt[v][j] == -1) continue;
          int k = kmp[v];
          while (k != 0 && nxt[k][j] == -1) k = kmp[k];
          if (nxt[k][j] != -1) k = nxt[k][j];
          kmp[nxt[v][j]] = k;
          sl[nxt[v][j]] = mark[k] ? k : sl[k];
          q.push(nxt[v][j]);
        }
      }
    }
  }
  // returns number of matched strings and marks 'found' array
  int match(const char *str, int found[]) {
    int j = 0, ret = 0;
    for (int i = 0, v; str[i] != '\0'; i++) {
      v = to(str[i]);
      while (j != 0 && nxt[j][v] == -1) j = kmp[j];
      if (nxt[j][v] != -1) j = nxt[j][v];
      v = j;
      do {
        if (mark[v] && !found[mark[v]])
          ret += found[mark[v]] = 1;
      } while (v = sl[v]);
    }
    return ret;
  }
}

int main() {
  int k;
  scanf("%d", &k);
  while (k--) {
    AHOC::reset();
    scanf("%s", STR);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%s", str[i]);
      ar[i] = 0;
      ans[i + 1] = 0;
      AHOC::add(str[i], i);
    }
    AHOC::build();
    AHOC::match(STR, ans);
    for (int i = 0; i < n; i++) {
      printf("%s\n", ans[ar[i]] ? "y" : "n");
    }
  }
  return 0;
}
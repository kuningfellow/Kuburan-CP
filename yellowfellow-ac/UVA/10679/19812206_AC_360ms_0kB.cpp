//UVA 10679 I Love Strings!!
//Aho-Corasick
//previous submission should be WA?
//corrected suffix link condition checking
#include<stdio.h>
#include<string.h>
#include<queue>
char STR[100005];
char str[1005][1005];
int ar[1005];
int ans[1005];
namespace aho {
  const int size = 1000005;
  const int sigma = 52;
  int nxt[size][sigma];
  int mark[size], kmp[size], sl[size];
  int gptr;
  int to(char x) {
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
  void fill(int x) {
    int ptr = 0, i = 0;
    while (str[x][i] != '\0') {
      int t = to(str[x][i]);
      if (nxt[ptr][t] == -1)
        nxt[ptr][t] = ++gptr;
      ptr = nxt[ptr][t];
      i++;
    }
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
};
class solution {
public:
  solution() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
      scanf("%s", &STR);
      aho::reset();
      int n;
      scanf("%d", &n);
      for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
        ar[i] = 0;
        ans[i + 1] = 0;
        aho::fill(i);
      }
      aho::build();
      int j = 0;
      for (int i = 0; STR[i] != '\0'; i++) {
        while (j != 0 && aho::nxt[j][aho::to(STR[i])] == -1) j = aho::kmp[j];
        if (aho::nxt[j][aho::to(STR[i])] != -1) j = aho::nxt[j][aho::to(STR[i])];
        int tmp = j;
        while (tmp != 0) {
          if (aho::mark[tmp] != -1) ans[aho::mark[tmp]] = 1;
          tmp = aho::sl[tmp];
        }
      }
      for (int i = 0; i < n; i++) {
        printf("%s\n", ans[ar[i]] ? "y" : "n");
      }
    }
  }
};

#ifndef L0C4L
int main() {
  solution();
  return 0;
}
#endif
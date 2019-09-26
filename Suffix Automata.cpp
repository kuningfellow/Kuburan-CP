namespace SA {
  const int maxL = 800005;
  const int sigma = 26;
  LL dp[maxL * 2];
  int nxt[maxL * 2][sigma];
  int sl[maxL * 2], ln[maxL * 2];
  int ptr, last;
  void clear(int x, int m = -1) {
    dp[x] = -1;
    if (m < 0) for (int i = 0; i < sigma; i++) nxt[x][i] = -1;
    else for (int i = 0; i < sigma; i++) nxt[x][i] = nxt[m][i];
  }
  void init() {
    sl[ln[ptr = 0] = 0] = -1;
    last = 0;
    clear(0);
  }
  void addchar(char c) {
    int x = c - 'A';
    int cur = ++ptr;
    clear(cur);
    ln[cur] = ln[last] + 1;
    int p = last;
    while (p != -1 && nxt[p][x] == -1) {
      nxt[p][x] = cur;
      p = sl[p];
    }
    if (p == -1) {
      sl[cur] = 0;
    } else {
      int q = nxt[p][x];
      if (ln[q] == ln[p] + 1) {
        sl[cur] = q;
      } else {
        int clone = ++ptr;
        clear(clone, q);
        sl[clone] = sl[q];
        ln[clone] = ln[p] + 1;
        while (p != -1 && nxt[p][x] == q) {
          nxt[p][x] = clone;
          p = sl[p];
        }
        sl[q] = sl[cur] = clone;
      }
    }
    last = cur;
  }
  LL serc(int x) {
    if (x == -1) return 0;
    if (dp[x] != -1) return dp[x];
    dp[x] = x != 0;
    for (int i = 0; i < sigma; i++) {
      dp[x] += serc(nxt[x][i]);
    }
    return dp[x];
  }
}
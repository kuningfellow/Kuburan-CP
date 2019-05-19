namespace aho {
  const int size = 1000005;
  const int sigma = 52;
  int nxt[size][sigma];
  int mark[size], kmp[size], sl[size];
  int gptr;
  int to(char x) {
    //zero based char to int mapping function
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
      // str[x] array of string pattern
      int t = to(str[x][i]);
      if (nxt[ptr][t] == -1)
        nxt[ptr][t] = ++gptr;
      ptr = nxt[ptr][t];
      i++;
    }
    mark[ptr] = x;  // x-th string
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
}

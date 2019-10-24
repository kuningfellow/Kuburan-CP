// also known as Hungarian algorithm
namespace KuhnMunkres {
  const int maxN = 500;
  int N;
  int d[maxN];
  int cost[maxN][maxN];
  int lX[maxN], lY[maxN];
  int mX[maxN], mY[maxN], bt[maxN], dx[maxN];
  int S[maxN], T[maxN];
  void init(int n) {
    N = n;
    for (int i = 0; i < N; i++) {
      mX[i] = mY[i] = -1;
      lX[i] = lY[i] = 0;
      for (int j = 0; j < N; j++)
        if (lX[i] < cost[i][j])
          lX[i] = cost[i][j];
    }
  }
  void add(int o, int n) {
    S[n] = 1;
    bt[n] = o;
    for (int i = 0; i < N; i++) {
      if (lX[n] + lY[i] - cost[n][i] < d[i]) {
        d[i] = lX[n] + lY[i] - cost[n][i];
        dx[i] = n;
      }
    }
  }
  void iterate() {
    for (int i = 0; i < N; i++) {
      S[i] = T[i] = 0;
      bt[i] = -1;
    }
    int x, y = N;
    queue<int> q;
    for (int i = 0; i < N; i++) {
      if (mX[i] == -1) {
        S[x = i] = 1;
        q.push(x);
        break;
      }
    }
    for (int i = 0; i < N; i++) {
      d[i] = lX[x] + lY[i] - cost[x][i];
      dx[i] = x;
    }
    while (y == N) {
      while (!q.empty() && y == N) {
        x = q.front();
        q.pop();
        for (y = 0; y < N; y++) {
          if (!T[y] && cost[x][y] == lX[x] + lY[y]) {
            if (mY[y] == -1) {
              break;
            } else {
              T[y] = 1;
              q.push(mY[y]);
              add(x, mY[y]);
            }
          }
        }
      }
      if (y < N) break;
      while (!q.empty()) q.pop();
      int red = ~(1 << 31);
      for (int i = 0; i < N; i++)
        if (!T[i] && red > d[i]) red = d[i];
      for (int i = 0; i < N; i++) {
        if (S[i]) lX[i] -= red;
        if (T[i]) lY[i] += red;
        if (!T[i]) d[i] -= red;
      }
      for (y = 0; y < N; y++) {
        if (!T[y] && d[y] == 0) {
          if (mY[y] == -1) {
            x = dx[y];
            break;
          } else {
            T[y] = 1;
            if (!S[mY[y]]) {
              q.push(mY[y]);
              add(dx[y], mY[y]);
            }
          }
        }
      }
    }
    for (int tmp; x != -1; x = bt[x], y = tmp) {
      tmp = mX[x], mX[x] = y, mY[y] = x;
    }
  }
  int match(int n) {
    init(n);
    for (int i = 0; i < N; i++) {
      iterate();
    }
    int res = 0;
    for (int i = 0; i < N; i++) {
      res += cost[i][mX[i]];
    }
    return res;
  }
}

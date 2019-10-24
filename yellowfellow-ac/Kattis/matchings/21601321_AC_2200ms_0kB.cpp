#include<stdio.h>
#include<complex>

using namespace std;

namespace fft {
  typedef complex<double> comp;
  const int maxLogN = 21;
  const double PI = acos(-1);
  int cor[1 << maxLogN][maxLogN + 1];
  int getpow(int x) {
    int r = 0;
    while ((1 << r) < x) r++;
    return r;
  }
  int bitrev(int x, int n) {
    int r = 0;
    for (int i = 0; i < n; i++, x >>= 1)
      r <<= 1, r |= (x & 1);
    return r;
  }
  void init(int x) {
    x = getpow(x);
    for (int j = 0; j < (1 << x); j++)
      cor[j][x] = bitrev(j, x);
  }
  void fft(comp *ar, int p, int mode) { // 1 for normal, -1 for inverse
    int L = 1 << p;
    for (int i = 0; i < L; i++) if (cor[i][p] > i) swap(ar[i], ar[cor[i][p]]);
    for (int i = 1; i <= p; i++) {
      int l = (1 << i);
      comp base(cos(2*PI/l), mode * sin(2*PI/l));
      comp cur(1, 0);
      for (int j = 0; j < l/2; j++) {
        for (int k = 0; k < L; k += l) {
          comp A = ar[k + j];
          comp B = cur * ar[k + j+l/2];
          ar[k + j] = A + B;
          ar[k + j+l/2] = A - B;
        }
        cur *= base;
      }
    }
  }
  void convolve(comp *ar, comp *br, int l) {
    for (l = 1 << l; l >= 0; l--)
      ar[l] = ar[l] * br[l];
  }
}

fft::comp pola[1 << 21], polb[1 << 21];
int ar[1005][1005], br[1005][1005];
int ans[1005][1005];
int n, m, N, M;

void solfe() {
  int p = fft::getpow(n*M + N*M);
  for (int i = 1 << p; i >= 0; i--) {
    pola[i].real(0);
    pola[i].imag(0);
    polb[i].real(0);
    polb[i].imag(0);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      pola[i * M + j].real(ar[i][j] == 0 ? -1 : 1);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      polb[M*n - 1 - i*M - j].real(br[i][j] == 0 ? -1 : 1);
    }
  }
  fft::fft(pola, p, 1);
  fft::fft(polb, p, 1);
  fft::convolve(pola, polb, p);
  fft::fft(pola, p, -1);
  double l = 1 << p;
  for (int i = 0; i <= N-n; i++) {
    for (int j = 0; j <= M-m; j++) {
      ans[i][j] += pola[i*M + j + M*n - 1].real() / l + 0.5;
    }
  }
}

int main() {
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &br[i][j]);
    }
  }
  scanf("%d %d", &M, &N);
  fft::init(M*N + n*M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &ar[i][j]);
    }
  }
  solfe();
  int best = -1e9;
  for (int i = 0; i <= N-n; i++) {
    for (int j = 0; j <= M-m; j++) {
      if (ans[i][j] > best) {
        best = ans[i][j];
      }
    }
  }
  for (int j = 0; j <= M-m; j++) {
    for (int i = 0; i <= N-n; i++) {
      if (ans[i][j] == best) {
        printf("%d %d\n", j, i);
      }
    }
  }
  return 0;
}
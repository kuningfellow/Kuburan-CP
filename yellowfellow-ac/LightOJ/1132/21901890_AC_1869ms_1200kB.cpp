#include<stdio.h>

typedef unsigned int uint;
const int maxK = 50 + 2;
uint res[maxK][maxK];
uint mul[maxK][maxK];
uint tmp[maxK][maxK];
uint tab[maxK][maxK];

void powe() {
  for (int i = 0; i < maxK; i++) {
    for (int j = 0; j < maxK; j++) {
      tmp[i][j] = 0;
      for (int k = 0; k < maxK; k++) {
        tmp[i][j] += mul[i][k] * mul[k][j];
      }
    }
  }
  for (int i = 0; i < maxK; i++) {
    for (int j = 0; j < maxK; j++) {
      mul[i][j] = tmp[i][j];
    }
  }
}
void mule() {
  for (int i = 0; i < maxK; i++) {
    for (int j = 0; j < maxK; j++) {
      tmp[i][j] = 0;
      for (int k = 0; k < maxK; k++) {
        tmp[i][j] += res[i][k] * mul[k][j];
      }
    }
  }
  for (int i = 0; i < maxK; i++) {
    for (int j = 0; j < maxK; j++) {
      res[i][j] = tmp[i][j];
    }
  }
}
void gentable() {
  tab[0][0] = 1;
  for (int i = 1; i < maxK; i++) {
    tab[i][0] = 1;
    tab[i][i] = 1;
    for (int j = 1; j < i; j++) {
      tab[i][j] = tab[i-1][j-1] + tab[i-1][j];
    }
  }
}
void init(int k) {
  for (int i = 0; i < maxK; i++) {
    for (int j = 0; j < maxK; j++) {
      res[i][j] = mul[i][j] = 0;
      if (i == j) res[i][j] = 1;
      if (i && j >= i) mul[i][j] = tab[maxK-1-i][j-i];
    }
  }
  mul[0][0] = mul[0][maxK - 1 - k] = 1;
}

int main() {
  gentable();
  int tc, kas = 0;
  scanf("%d", &tc);
  while (tc--) {
    long long int n;
    int ans = 0;
    int k;
    scanf("%lld %d", &n, &k);
    init(k);
    while (n) {
      if (n % 2) {
        mule();
      }
      powe();
      n /= 2;
    }
    for (int i = 1; i < maxK; i++) {
      ans += res[0][i];
    }
    printf("Case %d: %u\n", ++kas, ans);
  }
  return 0;
}
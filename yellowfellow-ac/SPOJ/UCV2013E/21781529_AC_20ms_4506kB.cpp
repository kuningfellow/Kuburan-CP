#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>

typedef long long int LL;
const LL MOD = 1000000007;

LL fexpo(LL base, int p) {
  LL ret = 1;
  while (p) {
    if (p % 2) ret = ret * base % MOD;
    base = base * base % MOD;
    p /= 2;
  }
  return ret;
}
LL fac[505];
int ar[55];

int main() {
  fac[0] = 1;
  for (int i = 1; i < 505; i++) {
    fac[i] = fac[i - 1] * i % MOD;
  }
  int n;
  while (1 < 2) {
    scanf("%d", &n);
    if (n == 0) break;
    int tot = 0;
    LL div = 1;
    for (int i = 0; i < n; i++) {
      scanf("%d", &ar[i]);
    }
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      x -= ar[i];
      if (x < 0) tot = -1;
      if (tot >= 0) {
        div = div * fac[x] % MOD;
        tot += x;
      }
    }
    printf("%lld\n", fac[tot] * fexpo(div, MOD - 2) % MOD);
  }
  return 0;
}
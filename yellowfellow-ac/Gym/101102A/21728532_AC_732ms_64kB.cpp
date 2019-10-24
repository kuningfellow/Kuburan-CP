#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>

typedef long long int LL;
const LL MOD = 1000000007;

LL dp[15005];
LL dp2[15005];

int abs(int x) {
  return x < 0 ? -x : x;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, m, k, w;
    scanf("%d %d %d %d", &n, &m, &k, &w);
    for (int i = 0; i < 15005; i++) {
      dp[i] = dp2[i] = 0;
    }
    dp[0] = dp2[0] = 1;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      for (int j = 15000; j >= x; j--) {
        dp[j] = (dp[j] + dp[j - x]) % MOD;
      }
    }
    for (int i = 0; i < m; i++) {
      int x;
      scanf("%d", &x);
      for (int j = 15000; j >= x; j--) {
        dp2[j] = (dp2[j] + dp2[j - x]) % MOD;
      }
    }
    LL ans = 0;
    for (int i = 0; i <= 15000; i++) {
      if (i > w) break;
      if (abs(i*2 - w) <= k) {
        ans = (ans + dp[i] * dp2[w - i] % MOD) % MOD;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
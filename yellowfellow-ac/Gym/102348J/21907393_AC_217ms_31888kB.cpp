#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<algorithm>

using namespace std;

typedef long long int LL;
const LL MOD = 998244353;

LL dp[200005][3][3];
LL fexpos[200005];
int ar[200005];
LL P, Q;
int n;

int add(int x, int a, int p, int pp) {
  if (x == 0) {
    return 0;
  } else if (a == 0) {
    return ar[x-1] + p != ar[x];
  } else if (a == -1 && (x == 1 || ar[x-2] + pp != ar[x-1])) {
    return ar[x-1] + p != ar[x-1] && ar[x] - 1 == ar[x-1];
  } else if (a == 1) {
    return x < n && ar[x] + 1 == ar[x+1];
  } else {
    return 0;
  }
}

LL fexpo(LL base, LL p) {
  LL ret = 1;
  while (p) {
    if (p % 2) {
      ret = ret * base % MOD;
    }
    base = base * base % MOD;
    p /= 2;
  }
  return ret;
}

LL serc(int x, int p, int pp) {
  if (x == n + 1) return 0;
  if (dp[x][p+1][pp+1] != -1) return dp[x][p+1][pp+1];
  LL &ret = dp[x][p+1][pp+1];
  ret = 0;
  LL mul = fexpos[n-x];
  ret = (ret + (1000000-P-Q) * (serc(x+1, 0, p) + add(x, 0, p, pp) * mul % MOD) % MOD) % MOD;
  ret = (ret + P * (serc(x+1, -1, p) + add(x, -1, p, pp) * mul % MOD) % MOD) % MOD;
  ret = (ret + Q * (serc(x+1, 1, p) + add(x, 1, p, pp) * mul % MOD) % MOD) % MOD;
  return ret;
}

int main() {
  scanf("%d %lld %lld", &n, &P, &Q);
  ar[0] = -69;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
  }
  fexpos[0] = 1;
  for (int i = 0; i <= n; i++) {
    if (i) {
      fexpos[i] = fexpos[i-1] * 1000000 % MOD;
    }
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  sort(ar + 1, ar + n + 1);
  LL ans = serc(1, 0, 0) * fexpo(fexpos[n], MOD-2) % MOD;
  printf("%lld\n", ans);
  return 0;
}

#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>

typedef long long int LL;

const LL MOD = 1000000007;

LL gcd(LL a, LL b) {
  if (!a) return b;
  if (!b) return a;
  LL rem = 1;
  while (rem) {
    rem = a % b;
    a = b;
    b = rem;
  }
  return a;;
}

int main() {
  LL n, m, r, c;
  scanf("%lld %lld %lld %lld", &n, &m, &r, &c);
  LL gM = gcd(m, c);
  LL dM = m / gM * (m + gM)/ 2 % MOD;
  LL gN = gcd(n, r);
  LL dN = n / gN * (n + gN - 2) / 2 % MOD;
  DEBUG(printf("%d %d %d %d\n", gM, dM, gN, dN);)
  dN = dN * m % MOD;
  LL rM = m / gM;
  LL rN = n / gN;
  LL rep = rM / gcd(rM, rN) * rN;
  LL ans = (rep / rM * dM % MOD + rep / rN * dN % MOD) % MOD;
  printf("%lld\n", ans);
}
#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>

int main() {
  long long int n;
  scanf("%lld", &n);
  int ans = 0;
  while (n) {
    if (n % 2) ans++;
    n /= 2;
  }
  printf("%lld\n", (1ll << ans));
  return 0;
}
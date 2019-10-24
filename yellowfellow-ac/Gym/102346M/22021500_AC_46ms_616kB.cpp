#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>

typedef long long int LL;

LL ar[100005];

int main() {
  int n, c, t;
  scanf("%d %d %d", &n, &c, &t);
  LL tot = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &ar[i]);
    tot += ar[i];
  }
  LL l = 0, r = tot;
  LL ans = tot;
  while (l <= r) {
    LL mid = (l + r)/2;
    LL tmp = -1;
    int _c = c, val = 1;
    for (int i = 0; i < n && val; i++) {
      if (tmp == -1) {
        tmp = ar[i];
        _c--;
      } else {
        if ((tmp + ar[i] + t-1) / t <= mid) {
          tmp += ar[i];
        } else {
          tmp = ar[i];
          _c--;
        }
      }
      if ((tmp + t-1)/t > mid) val = 0;
      if (_c < 0) val = 0;
    }
    if (val) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */

#include<stdio.h>
#include<math.h>
#include<string.h>

int ar[200005];
int block[450];

int main() {
  int kas = 0;
  int n;
  while (scanf("%d", &n) && n) {
    int bs = round(sqrt(n));
    for (int i = 0; i < n; i++) {
      scanf("%d", &ar[i]);
      if (i % bs == 0) block[i / bs] = 0;
      block[i / bs] += ar[i];
    }
    if (kas) printf("\n");
    printf("Case %d:\n", ++kas);
    while (1 < 2) {
      char que[5];
      int x, y;
      scanf("%s", que);
      if (!strcmp(que, "END")) break;
      else if (que[0] == 'S') {
        scanf("%d %d", &x, &y);
        x--;
        block[x / bs] += y - ar[x];
        ar[x] = y;
      } else {
        scanf("%d %d", &x, &y);
        x--, y--;
        int bl = x/bs, br = y/bs, ans = 0;
        ans += ar[x++];
        for (int i = bl + 1; i < br; i++) {
          ans += block[i];
        }
        while (x/bs == (x-1)/bs && x <= y) {
          ans += ar[x++];
        }
        while (y >= x) {
          ans += ar[y--];
          if (y/bs != (y+1)/bs) break;
        }
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>

char str[100005];

int rev[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d %s", &n, str);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += rev[str[i] - '0'];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 9; j >= 0; j--) {
        if (cnt < rev[j]) continue;
        if ((cnt - rev[j] + 6)/7 <= (n-i-1) && (n-i-1) <= (cnt - rev[j])/2) {
          printf("%d", j);
          cnt -= rev[j];
          break;
        }
      }
    }
    printf("\n");
  }
  return 0;
}
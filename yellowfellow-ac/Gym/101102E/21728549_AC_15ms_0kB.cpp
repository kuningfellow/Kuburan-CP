#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", (n + 4) / 5);
  }
  return 0;
}
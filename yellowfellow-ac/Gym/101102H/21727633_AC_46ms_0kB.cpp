#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<string.h>

char str[100005];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, k;
    scanf("%d %d", &n, &k);
    k++;
    scanf("%s", str);
    int foun = 0;
    for (int i = 0, j = 0; i < n; i++) {
      if (str[i] == '0') {
        j++;
      } else {
        j = 0;
      }
      if (j > foun) foun = j;
    }
    if (foun >= k) printf("yes\n");
    else printf("no\n");
  }
  return 0;
}
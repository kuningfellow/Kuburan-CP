#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>

struct node {
  char c;
  int le, ri;
};

node ar[200008];
char str[100005];

int main() {
  int n, m, P1[2], P2[2];
  scanf("%d %d %d %s", &n, &P1[0], &P1[1], str);
  P2[0] = P1[0] + n + 2;
  P2[1] = P1[1] + n + 2;
  for (int i = 0; i <= n+1; i++) {
    if (i && i < n+1) ar[i + n+2].c = ar[i].c = str[i - 1];
    if (i) ar[i].le = i-1, ar[i + n+2].ri = i+n+2-1;
    if (i < n+1) ar[i].ri = i+1, ar[i + n+2].le = i+n+2+1;
  }
  scanf("%d", &m);
  while (m--) {
    char que[5];
    scanf("%s", que);
    if (que[0] == 'S') {
      int p = 0;
      char X[5], Y[5];
      scanf("%s %s", X, Y);
      if (X[0] == 'R') p = 1;
      if (Y[0] == 'L') {
        P1[p] = ar[P1[p]].le;
        P2[p] = ar[P2[p]].ri;
      } else {
        P1[p] = ar[P1[p]].ri;
        P2[p] = ar[P2[p]].le;
      }
    } else if (que[0] == 'R') {
      if (P1[0] != P1[1]) {
        int le = ar[P1[0]].le;
        int ri = ar[P1[1]].ri;
        int le2 = ar[P2[0]].ri;
        int ri2 = ar[P2[1]].le;

        ar[le].ri = P2[1];
        ar[P2[1]].le = le;
        ar[ri].le = P2[0];
        ar[P2[0]].ri = ri;

        ar[le2].le = P1[1];
        ar[P1[1]].ri = le2;
        ar[ri2].ri = P1[0];
        ar[P1[0]].le = ri2;

        P1[0] ^= P2[1] ^= P1[0] ^= P2[1];
        P1[1] ^= P2[0] ^= P1[1] ^= P2[0];
      }
    } else {
      char X[5];
      scanf("%s", X);
      if (X[0] == 'L') printf("%c", ar[P1[0]].c);
      else printf("%c", ar[P1[1]].c);
    }
    // DEBUG(
    //   printf("%d %d\n", P1[0], P1[1]);
    //   int p = ar[0].ri;
    //   for (int i = 0; i < n; i++) {
    //     printf("%c", ar[p].c);
    //     p = ar[p].ri;
    //   }
    //   printf("\n");
    // )
  }
  printf("\n");
  return 0;
}
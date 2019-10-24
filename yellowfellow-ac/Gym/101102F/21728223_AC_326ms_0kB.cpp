#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<string.h>

char str[100005];
int mark[26];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%s", str);
    for (int i = 0; i < 26; i++) {
      mark[i] = 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
      mark[str[i] - 'a'] = 1;
    }
    int a = -1, b = -1;
    for (int i = 0; str[i] != '\0' && a == -1; i++) {
      mark[str[i] - 'a'] = 0;
      for (int j = 0; j < str[i] - 'a'; j++) {
        if (mark[j] == 1) {
          a = str[i] - 'a';
          b = j;
          break;
        }
      }
    }
    for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] == 'a' + a) printf("%c", b + 'a');
      else if (str[i] == 'a' + b) printf("%c", a + 'a');
      else printf("%c", str[i]);
    }
    printf("\n");
  }
  return 0;
}
#include<stdio.h>

int main() {
  long long int k;
  scanf("%lld", &k);
  int a = 0;
  printf("%c", a + 'a');
  a++;
  k--;
  while (a < 26 && k > 0) {
    for (int i = 1; k; i++) {
      if (k - (i%2 == 0) * 2 - i > 0) {
        k -= (i%2==0) * 2 + i;
        printf("%c", a + 'a');
      }
      else break;
    }
    a++;
    printf("%c", a + 'a');
    k--;
    if (k) {
      a++;
      printf("%c", a + 'a');
      k--;
    }
    a++;
  }
  printf("\n");
  return 0;
}
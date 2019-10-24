#include<stdio.h>

int main() {
  int n;
  int odd = 0;
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    if (x % 2) odd++;
  }
  if (odd % 2 == 0) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
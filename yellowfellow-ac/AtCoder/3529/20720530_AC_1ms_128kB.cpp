#include<stdio.h>

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  while (n--) {
    int l, r;
    scanf("%d %d", &l, &r);
    ans += r - l + 1;
  }
  printf("%d\n", ans);
  return 0;
}
#include<stdio.h>

typedef long long int LL;

LL ar[100005];

int main() {
  int n;
  LL s;
  scanf("%d %lld", &n, &s);
  ar[0] = 1;
  for (int i = 1; i <= n; i++) {
    LL x;
    scanf("%lld", &x);
    if (ar[i - 1] == -1 || ar[i-1] * x > s) ar[i] = -1;
    else ar[i] = ar[i-1] * x;
  }
  int ans = 0;
  for (int i = n; i >= 0; i--) {
    if (ar[i] == -1) continue;
    ans += s / ar[i];
    s %= ar[i];
  }
  printf("%d\n", ans);
  return 0;
}
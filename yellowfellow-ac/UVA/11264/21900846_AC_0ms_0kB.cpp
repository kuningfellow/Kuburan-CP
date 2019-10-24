#include<stdio.h>

typedef long long int LL;

LL ar[1005];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lld", &ar[i]);
    }
    LL tot = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (i == n-1 || tot + ar[i] < ar[i+1]) {
        ans++;
        tot += ar[i];
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

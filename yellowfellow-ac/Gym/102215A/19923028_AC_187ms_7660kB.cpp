#ifdef Kelly
#include<DEBUG.h>
#else
#define DEBUG(...)
#endif
/*-------------------------------<   Kelly   >-------------------------------*/
#include<stdio.h>

int br[500005];
int ar[500005];
int last[500005];
int dp[500005];

int min(int a, int b) {
  return a < b ? a : b;
}
int abs(int a) {
  return a < 0 ? -a : a;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ar[i]);
    last[i + 1] = n - 1;
    dp[i + 1] = n;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (ar[i] > 0) {
      dp[ar[i]] = i;
      br[i] = last[ar[i]];
    } else {
      last[abs(ar[i])] = dp[abs(ar[i])] - 1;
      br[i] = last[abs(ar[i])];
    }
  }
  for (int i = n - 1, j = n; i >= 0; i--) {
    j = min(j , br[i]);
    dp[i] = j;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", dp[i] - i + 1);
  }
  printf("\n");
  return 0;
}


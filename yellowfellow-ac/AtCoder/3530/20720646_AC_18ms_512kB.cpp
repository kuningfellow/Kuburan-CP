#include<stdio.h>
#include<algorithm>

using namespace std;

int ar[100005];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ar[i]);
  }
  sort(ar, ar + n);
  int ans = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (i && ar[i] != ar[i-1]) {
      if (j % 2) {
        ans++;
      }
      j = 0;
    }
    j++;
  }
  if (j % 2) ans++;
  printf("%d\n", ans);
  return 0;
}
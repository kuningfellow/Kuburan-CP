#include<stdio.h>
#include<algorithm>

using namespace std;

int ar[105];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ar[i]);
  }
  sort(ar, ar + n);
  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (ar[i-1] < ar[i]) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
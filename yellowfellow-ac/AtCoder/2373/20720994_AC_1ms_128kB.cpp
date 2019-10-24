#include<stdio.h>
#include<algorithm>

using namespace std;

int ar[3];

int main() {
  for (int i = 0; i < 3; i++) {
    scanf("%d", &ar[i]);
  }
  if (ar[0] == ar[1] && ar[1] == ar[2] && ar[0] % 2 == 0) {
    printf("-1\n");
  } else {
    int ans = 0;
    while (ar[0] % 2 == 0 && ar[1] % 2 == 0 && ar[2] % 2 == 0) {
      int ta = ar[1] / 2 + ar[2] / 2;
      int tb = ar[0] / 2 + ar[2] / 2;
      int tc = ar[0] / 2 + ar[1] / 2;
      ar[0] = ta;
      ar[1] = tb;
      ar[2] = tc;
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
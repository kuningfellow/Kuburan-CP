#ifdef Kelly
#include<DEBUG.h>
#else
#define DEBUG(...)
#endif
/*-------------------------------<   Kelly   >-------------------------------*/
#include<stdio.h>
#include<string.h>

char str[2][1005];

int main() {
  scanf("%s %s", str[0], str[1]);
  int n = strlen(str[0]);
  int u = 0, d = 0, b = 0, e = 0;
  for (int i = 0; i < n; i++) {
    if (str[0][i] == str[1][i] && str[0][i] == '#') b++;
    else if (str[0][i] == '#') u++;
    else if (str[1][i] == '#') d++;
    else e++;
  }
  if (u > 0 && d > 0 && b == 0) {
    printf("NO\n");
  } else {
    int x = 0;
    while (u > 0) {
      str[0][x] = '#';
      str[1][x] = '.';
      u--;
      x++;
    }
    while (b > 0) {
      str[0][x] = '#';
      str[1][x] = '#';
      b--;
      x++;
    }
    while (d > 0) {
      str[0][x] = '.';
      str[1][x] = '#';
      d--;
      x++;
    }
    while (e > 0) {
      str[0][x] = '.';
      str[1][x] = '.';
      e--;
      x++;
    }
    printf("YES\n%s\n%s\n", str[0], str[1]);
  }
  return 0;
}


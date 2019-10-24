#ifdef Kelly
#include<DEBUG.h>
#else
#define DEBUG(...)
#endif
/*-------------------------------<   Kelly   >-------------------------------*/
#include<stdio.h>
#include<algorithm>

using namespace std;
const int maxN = 200000;

struct dat {
  int l, r, id;
  bool operator<(const dat& o) {
    if (l < o.l) return true;
    else if (l > o.l) return false;
    else if (r > o.r) return true;
    else return false;
  }
};

dat ar[maxN];
int ans[maxN];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &ar[i].l, &ar[i].r);
    ar[i].id = i + 1;
  }

  sort(ar, ar + n);
  int j = 0, k = -1;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (ar[i].l > j + 1 && k != -1) {
      ans[cnt++] = ar[k].id;
      j = ar[k].r;
      k = -1;
    }
    if (ar[i].l > j + 1) {
      cnt = -1;
      break;
    } else if (ar[i].l == j + 1) {
      if (k != -1 && ar[k].r > ar[i].r) {
        ans[cnt++] = ar[k].id;
        j = ar[k].r;
      } else {
        ans[cnt++] = ar[i].id;
        j = ar[i].r;
      }
      k = -1;
    } else if (j < ar[i].r && (k == -1 || ar[k].r < ar[i].r)) {
      k = i;
    }
  }
  if (cnt != -1 && k != -1) {
    j = ar[k].r;
    ans[cnt++]=ar[k].id;
  }
  if (j < m) cnt = -1;
  if (cnt == -1) printf("NO\n");
  else {
    printf("YES\n%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
#ifdef Kelly
#include<DEBUG.h>
#else
#define DEBUG(...)
#endif
/*-------------------------------<   Kelly   >-------------------------------*/
#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

struct dat {
  int a, h, id;
  bool operator<(const dat& o) {
    if (a < o.a) return true;
    return false;
  }
};
struct dat2 {
  int a, h, id;
  bool operator<(const dat2& o) {
    if (h > o.h) return true;
    return false;
  }
};

dat ar[300005];
dat2 br[300005];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &ar[i].a, &ar[i].h);
    br[i].a = ar[i].a;
    br[i].h = ar[i].h;
    br[i].id = ar[i].id = i + 1;
  }
  sort(ar, ar + n);
  sort(br, br + n);
  int x = -1, y = -1;
  auto cost = [](int a, int b) {
    int ret = 0;
    if (ar[a].a >= ar[b].h) ret += ar[b].a;
    if (ar[b].a >= ar[a].h) ret += ar[a].a;
    return ret;
  };
  priority_queue<pair<int,int>>pq;

  for (int i = 0, j = -1; i < n; i++) {
    DEBUG("%d %d\n", ar[i].a, ar[i].h);
    while (!pq.empty() && -pq.top().first <= ar[i].a) {
      if (j == -1 || ar[j].a < ar[pq.top().second].a) {
        j = pq.top().second;
      }
      pq.pop();
    }
    if (j != -1) {
      if (x == -1 || cost(i, j) > cost(x, y)) {
        x = i;
        y = j;
      }
    }
    pq.push(pair<int,int>(-ar[i].h, i));
  }
  while (!pq.empty()) pq.pop();

  for (int i = 0, j = -1; i < n; i++) {
    if (j != -1) {
      if (x == -1 || cost(i, j) > cost(x, y)) {
        x = i;
        y = j;
      }
    }
    if (j == -1 || ar[i].a > ar[j].a) {
      j = i;
    }
  }
  if (x == -1) x = 0, y = 1;
  printf("%d\n%d %d\n", cost(x, y), ar[x].id, ar[y].id);
  return 0;
}
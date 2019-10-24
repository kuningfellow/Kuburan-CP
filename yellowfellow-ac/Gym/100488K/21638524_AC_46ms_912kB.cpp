#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;
typedef long long int LL;

priority_queue<LL>rep;

int main() {
  int n;
  LL a = 0, b = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    if (i + 1 < n) {
      i++;
      LL x, y;
      scanf("%lld %lld", &x, &y);
      if (x < y) x ^= y ^= x ^= y;
      a += x;
      if (!rep.empty() && y > -rep.top()) {
        b += -rep.top();
        a -= -rep.top();
        a += y;
        rep.pop();
        rep.push(-y);
      } else {
        b += y;
      }
      rep.push(-x);
    } else {
      LL x;
      scanf("%lld", &x);
      a += x;
    }
  }
  printf("%lld %lld\n", a, b);
  return 0;
}
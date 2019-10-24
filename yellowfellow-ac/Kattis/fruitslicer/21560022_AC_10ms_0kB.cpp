#include<stdio.h>
#include<math.h>

struct point {
  double x, y;
};

double dist(point a, point b) {
  double u1 = b.x - a.x;
  double u2 = b.y - a.y;
  return sqrt(u1*u1 + u2*u2);
}

double cross(point a, point b, point c) {   // (c-a) perp (b-a)
  double u1 = b.x - a.x;
  double u2 = b.y - a.y;
  double v1 = c.x - a.x;
  double v2 = c.y - a.y;
  return (v1 * u2 - v2 * u1) / dist(a, b);
}


point P[105];

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &P[i].x, &P[i].y);
  }
  if (n <= 2) {
    ans = n;
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int c1 = 2, c2 = 2;
        int checkpoint = 0 ;
        if (dist(P[i], P[j]) < 1e-9) {
          checkpoint = 1;
        }
        for (int k = 0; k < n; k++) {
          if (k == i || k == j) continue;
          if (checkpoint == 1) {
            if (dist(P[i], P[k]) < 1e-9) {
              c1++;
              c2++;
            }
          } else {
            double dist = cross(P[i], P[j], P[k]);
            double d1 = abs(dist - 1);
            double d2 = abs(dist + 1);
            if (d1 < 1 + 1e-9) c1++;
            if (d2 < 1 + 1e-9) c2++;
          }
        }
        if (c1 > ans) ans = c1;
        if (c2 > ans) ans = c2;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
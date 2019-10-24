#include<stdio.h>
#include<math.h>

int main() {
  double a, b, c, r;
  scanf("%lf %lf %lf %lf", &a, &b, &c, &r);
  double A = acos((b*b + c*c - a*a) / 2 / b / c);
  double B = acos((a*a + c*c - b*b) / 2 / a / c);
  double C = acos((b*b + a*a - c*c) / 2 / a / b);
  double remA = r / tan(A/2) * r;
  double remB = r / tan(B/2) * r;
  double remC = r / tan(C/2) * r;
  double rem = remA + remB + remC - acos(-1)*r*r;
  double semi = (a + b + c) / 2;
  double triang = sqrt(semi * (semi - a) * (semi - b) * (semi - c));
  printf("%.9f\n", (triang - rem) / triang);
  return 0;
}
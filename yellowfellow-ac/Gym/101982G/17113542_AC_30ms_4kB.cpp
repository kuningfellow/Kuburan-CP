#include<bits/stdc++.h>
using namespace std;
double S(int a) {
    return (double)a*a;
}
int main() {
    int x, y, X1, Y1, X2, Y2;
    scanf("%d %d %d %d %d %d", &x, &y, &X1, &Y1, &X2, &Y2);
    double ans = (-1) ^ (1 << 31);
    double dist;
    if (X1 <= x && x <= X2) {
        ans = min(ans, fabs(y - Y2));
        ans = min(ans, fabs(y - Y1));
    }
    if (Y1 <= y && y <= Y2) {
        ans = min(ans, fabs(x - X1));
        ans = min(ans, fabs(x - X2));
    }

    ans = min(ans, sqrt(S(x-X1) + S(y-Y1)));
    ans = min(ans, sqrt(S(x-X1) + S(y-Y2)));
    ans = min(ans, sqrt(S(x-X2) + S(y-Y1)));
    ans = min(ans, sqrt(S(x-X2) + S(y-Y2)));
    printf("%.3f\n", ans);
}

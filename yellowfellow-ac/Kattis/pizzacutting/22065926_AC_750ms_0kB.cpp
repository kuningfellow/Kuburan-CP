#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;
const double EPS = 1e-9;
int dx, dy, _x0, _y0, R;

typedef pair<double,double> Pt;
vector<double>martabak;

bool inside(int x, int y) {
  return x*x + y*y <= R*R;
}
bool incircle(Pt a) {
  return abs(R*R - a.first*a.first - a.second*a.second) < EPS;
}
bool inbox(int x, int y, Pt a) {
  if (x <= a.first && a.first <= x + dx && y <= a.second && a.second <= y + dy) {
    return true;
  }
  return false;
}
double dist(Pt a, Pt b) {
  return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}
double area(double d) {
  double rad = asin(d / 2 / R);
  return rad*R*R - cos(rad)*R*d/2;
}
Pt chk(Pt a, Pt b, double d) {
  Pt mid;
  mid.first = (a.first + b.first) / 2;
  mid.second = (a.second + b.second) / 2;
  double len = dist(mid, Pt(0, 0));
  mid.first += d * mid.first / len;
  mid.second += d * mid.second / len;
  return mid;
}
double cross(Pt a, Pt b, Pt c) {
  double v1 = a.first - c.first;
  double v2 = a.second - c.second;
  double u1 = b.first - c.first;
  double u2 = b.second - c.second;
  return v1 * u2 - v2 * u1;
}
double extra(Pt a, Pt b, int x, int y) {
  if (!incircle(a) || !incircle(b)) return 0;
  if (cross(b, a, Pt(0, 0)) < 0) return 0;
  double d = dist(a, b);
  double rad = asin(d / 2 / R);
  Pt c = chk(a, b, R * (1-cos(rad)));
  if (inbox(x, y, c)) {
    return rad*R*R - cos(rad)*R*d/2;
  }
  return 0;
}
vector<Pt> createConvexHull(vector<Pt> &points) {
  sort(points.begin(), points.end());
  vector<Pt> ret;
  for (int i = 0; i < points.size(); i++) {
    while (ret.size() > 1 &&
      cross(points[i], ret[ret.size()-1], ret[ret.size()-2]) < EPS)
      ret.pop_back();
    ret.push_back(points[i]);
  }
  for (int i = points.size() - 2, sz = ret.size(); i >= 0; i--) {
    while (ret.size() > sz &&
      cross(points[i], ret[ret.size()-1], ret[ret.size()-2]) < EPS)
      ret.pop_back();
    if (i == 0) break;
    ret.push_back(points[i]);
  }
  return ret;
}
double area(int x, int y) {
  vector<Pt> hull;
  int xdx = min(x+dx, R);
  int ydy = min(y+dy, R);
  x = max(x, -R);
  y = max(y, -R);
  if (inside(x, y)) hull.push_back(Pt(x, y));
  if (inside(xdx, y)) hull.push_back(Pt(xdx, y));
  if (inside(x, ydy)) hull.push_back(Pt(x, ydy));
  if (inside(xdx, ydy)) hull.push_back(Pt(xdx, ydy));
  double Y;
  if (R*R >= x*x) {
    Y = sqrt(R*R - x*x);
    if (y <= Y && Y <= ydy) hull.push_back(Pt(x, Y));
    if (y <= -Y && -Y <= ydy) hull.push_back(Pt(x, -Y));
  }
  if (R*R >= (xdx)*(xdx)) {
    Y = sqrt(R*R - (xdx)*(xdx));
    if (y <= Y && Y <= ydy) hull.push_back(Pt(xdx, Y));
    if (y <= -Y && -Y <= ydy) hull.push_back(Pt(xdx, -Y));
  }
  double X;
  if (R*R >= y*y) {
    X = sqrt(R*R - y*y);
    if (x <= X && X <= xdx) hull.push_back(Pt(X, y));
    if (x <= -X && -X <= xdx) hull.push_back(Pt(-X, y));
  }
  if (R*R >= (ydy)*(ydy)) {
    X = sqrt(R*R - (ydy)*(ydy));
    if (x <= X && X <= xdx) hull.push_back(Pt(X, ydy));
    if (x <= -X && -X <= xdx) hull.push_back(Pt(-X, ydy));
  }
  hull = createConvexHull(hull);
  int n = hull.size();
  double ans = 0;
  double ret = 0;
  for (int i = 0; i < n; i++) {
    ret += hull[i].first*hull[(i+1)%n].second - hull[i].second*hull[(i+1)%n].first;
    ans += extra(hull[i], hull[(i+1)%n], x, y);
  }
  return ans + abs(ret) / 2;
}

int main() {
  double p;
  scanf("%d %d %d %d %d %lf", &R, &dx, &dy, &_x0, &_y0, &p);
  int x = -R;
  while (((x-_x0)%dx+dx)%dx) x--;
  int y = -R;
  while (((y-_y0)%dy+dy)%dy) y--;
  double maxi = 0;
  for (int i = x; i <= R; i += dx) {
    for (int j = y; j <= R; j += dy) {
      double ret = area(i, j);
      if (ret > EPS) {
        DEBUG(printf("dapat %d %d %f\n", i, j, ret);)
        martabak.push_back(ret);
      }
      maxi = max(maxi, ret);
    }
  }
  int ans = 0;
  for (double makan : martabak) {
    if (makan / maxi - p < EPS) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
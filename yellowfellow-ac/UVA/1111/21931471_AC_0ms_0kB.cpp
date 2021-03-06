// test template

#include<stdio.h>

#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
typedef double TD;                // for precision shits
namespace GEOM {
  typedef pair<TD,TD> Pt;         // vector and points
  const TD EPS = 1e-9;
  const TD maxD = 1e9;
  TD cross(Pt a, Pt b, Pt c) {    // right hand rule
    TD v1 = a.first - c.first;    // (a-c) X (b-c)
    TD v2 = a.second - c.second;
    TD u1 = b.first - c.first;
    TD u2 = b.second - c.second;
    return v1 * u2 - v2 * u1;
  }
  TD cross(Pt a, Pt b) {          // a X b
    return a.first*b.second - a.second*b.first;
  }
  TD dot(Pt a, Pt b, Pt c) {      // (a-c) . (b-c)
    TD v1 = a.first - c.first;
    TD v2 = a.second - c.second;
    TD u1 = b.first - c.first;
    TD u2 = b.second - c.second;
    return v1 * u1 + v2 * u2;
  }
  TD dot(Pt a, Pt b) {            // a . b
    return a.first*b.first + a.second*b.second;
  }
  TD dist(Pt a, Pt b) {
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
  }
  TD shoelaceX2(vector<Pt> &convHull) {
    TD ret = 0;
    for (int i = 0, n = convHull.size(); i < n; i++)
      ret += cross(convHull[i], convHull[(i+1)%n]);
    return ret;
  }
  vector<Pt> createConvexHull(vector<Pt> &points) {
    sort(points.begin(), points.end());
    vector<Pt> ret;
    for (int i = 0; i < points.size(); i++) {
      while (ret.size() > 1 &&
        cross(points[i], ret[ret.size()-1], ret[ret.size()-2]) < -EPS)
        ret.pop_back();
      ret.push_back(points[i]);
    }
    for (int i = points.size() - 2, sz = ret.size(); i >= 0; i--) {
      while (ret.size() > sz &&
        cross(points[i], ret[ret.size()-1], ret[ret.size()-2]) < -EPS)
        ret.pop_back();
      if (i == 0) break;
      ret.push_back(points[i]);
    }
    return ret;
  }
  // set mod=0 to calculate furthest antipodal
  // set mod=1 to blow candles (minimum calipers)
  // set mod=2 to minimum bounding rectangle
  // return (antipodal, distance)
  vector<pair<int,TD> > rotateCalipers(const vector<Pt> &Pts, int mod = 0) {
    int ptr = 0, upd = 0, P1 = 0, P2 = 0;
    vector<pair<int,TD> > ret;
    for (int i = 0, n = Pts.size(); i < n; i++, upd = ptr) {
      TD d = -1, d1 = -1, d2 = maxD, tmp, l = dist(Pts[i], Pts[(i+1) % n]);
      for (int j = 0; j < n; j++) {
        if (d <= (tmp = fabs(cross(Pts[upd], Pts[(i+1)%n], Pts[i]))/l) + EPS) {
          d = tmp;
          if (mod == 0 && dot(Pts[upd], Pts[(i+1)%n], Pts[i]) >= 0 && 
              dot(Pts[upd], Pts[(i-1+n)%n], Pts[i]) >= 0)
            d = dist(Pts[i], Pts[upd]);
          upd = (upd + 1) % n;
        } else {
          break;
        }
      }
      ptr = (upd - 1 + n) % n;
      if (mod == 2) {
        while (d1 <= (tmp = dot(Pts[P1], Pts[(i+1)%n], Pts[i])/l) + EPS)
          d1 = tmp, P1 = (P1 + 1) % n;
        P1 = (P1 - 1 + n) % n;
        if (i == 0) P2 = P1;
        while (d2 >= (tmp = dot(Pts[P2], Pts[(i+1) % n], Pts[i])/l) - EPS)
          d2 = tmp, P2 = (P2 + 1) % n;
        P2 = (P2 - 1 + n) % n;
        d = (d + (d1 - d2)) * 2;    // untuk keliling
        // d = (d * (d1 - d2));        // untuk luas
      }
      ret.push_back(pair<int,TD>(upd, d));
    }
    return ret;
  }
}

vector<pair<TD,TD> > lis, hull;
vector<pair<int,TD> > ans;

int main() {
  int n, kas = 0;
  while (scanf("%d", &n)) {
    if (n == 0) break;
    lis.clear();
    ans.clear();
    for (int i = 0; i < n; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      lis.push_back(pair<TD,TD>(a, b));
    }
    ans = GEOM::rotateCalipers(GEOM::createConvexHull(lis), 1);
    double fin = 0;
    for (int i = 0; i < ans.size(); i++) {
      if (i == 0) fin = ans[i].second;
      fin = min(fin, ans[i].second);
    }
    printf("Case %d: %.2f\n", ++kas, fin);
  }
  return 0;
}
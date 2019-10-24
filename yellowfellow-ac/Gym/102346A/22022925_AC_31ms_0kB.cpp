#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<utility>

using namespace std;
typedef pair<int,int> Pt;

bool intersect(Pt a, int ra, Pt b, int rb = 0) {
  int dist = (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
  if ((ra + rb) * (ra + rb) >= dist) return true;
  return false;
}

Pt circ[1005];
int rad[1005];

int par[1010];
int finpar(int x) {
  if (par[x] == x) return x;
  return par[x] = finpar(par[x]);
}

int main() {
  int n, m, k, ans = 1;
  scanf("%d %d %d", &m, &n, &k);
  par[0] = 0;
  par[1] = 1;
  par[2] = 2;
  par[3] = 3;
  for (int i = 0; i < k; i++) {
    par[i + 4] = i + 4;
    scanf("%d %d %d", &circ[i].first, &circ[i].second, &rad[i]);
    if (intersect(circ[i], rad[i], Pt(0, 0)) || intersect(circ[i], rad[i], Pt(m, n))) {
      ans = 0;
    }
  }
  if (ans == 0) {
    printf("N\n");
  } else {
    for (int i = 0; i < k; i++) {
      for (int j = i + 1; j < k; j++) {
        if (finpar(i + 4) != finpar(j + 4) && intersect(circ[i], rad[i], circ[j], rad[j])) {
          par[finpar(i + 4)] = finpar(j + 4);
        }
      }
      if (finpar(i+4) != finpar(0) && intersect(circ[i], rad[i], Pt(circ[i].first, 0))) {
        par[finpar(i+4)] = finpar(0);
      }
      if (finpar(i+4) != finpar(1) && intersect(circ[i], rad[i], Pt(circ[i].first, n))) {
        par[finpar(i+4)] = finpar(1);
      }
      if (finpar(i+4) != finpar(2) && intersect(circ[i], rad[i], Pt(0, circ[i].second))) {
        par[finpar(i+4)] = finpar(2);
      }
      if (finpar(i+4) != finpar(3) && intersect(circ[i], rad[i], Pt(m, circ[i].second))) {
        par[finpar(i+4)] = finpar(3);
      }
    }
    if (finpar(0) == finpar(1) || finpar(0) == finpar(2) || finpar(1) == finpar(3) || finpar(2) == finpar(3)) {
      ans = 0;
    }
    if (ans) printf("S\n");
    else printf("N\n");
  }
  return 0;
}
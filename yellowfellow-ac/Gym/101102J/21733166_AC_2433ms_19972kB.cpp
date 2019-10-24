#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<vector>

using namespace std;

int cor[2550];

int ar[100005];
int cnte[100005][50];
vector<int> lcmlist, eval;

int gcd(int a, int b) {
  int rem = 1;
  while (rem) {
    rem = a % b;
    a = b;
    b = rem;
  }
  return a;
}

int calc(int P, int x, int idx, int cnt) {
  if (idx == eval.size()) {
    if (x == 0) return 0;
    return cnte[P][cor[x]] * (cnt % 2 == 1 ? 1 : -1);
  }
  int ret = calc(P, x, idx+1, cnt);
  if (x == 0) ret += calc(P, eval[idx], idx+1, cnt+1);
  else ret += calc(P, eval[idx] * x / gcd(eval[idx], x), idx+1, cnt+1);
  return ret;
}

int main() {
  for (int i = 0, tmp = 1; i < 4; i++) {
    for (int j = 0, tmp2 = tmp; j < 3; j++) {
      for (int k = 0, tmp3 = tmp2; k < 2; k++) {
        for (int l = 0, tmp4 = tmp3; l < 2; l++) {
          cor[tmp4] = lcmlist.size();
          lcmlist.push_back(tmp4);
          tmp4 *= 7;
        }
        tmp3 *= 5;
      }
      tmp2 *= 3;
    }
    tmp *= 2;
  }
  DEBUG(printf("%d\n", lcmlist.size());)
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < lcmlist.size(); j++) {
        cnte[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &ar[i]);
      for (int j = 0; j < lcmlist.size(); j++) {
        cnte[i][j] += cnte[i-1][j];
        if (ar[i] % lcmlist[j] == 0) {
          cnte[i][j]++;
        }
      }
    }
    for (int i = 0; i < q; i++) {
      int l, r, s;
      scanf("%d %d %d", &l, &r, &s);
      vector<int> tmp;
      for (int j = 0; j < 10; j++) {
        if (s & (1 << j)) {
          tmp.push_back(j + 1);
        }
      }
      for (int j = 0; j < tmp.size(); j++) {
        if (tmp[j] == -1) continue;
        for (int k = 0; k < tmp.size() && tmp[j] != -1; k++) {
          if (tmp[k] == -1) continue;
          if (k == j) continue;
          int g = gcd(tmp[j], tmp[k]);
          if (g == tmp[j]) tmp[k] = -1;
        }
      }
      for (int j = 0; j < tmp.size(); j++) {
        if (tmp[j] != -1) eval.push_back(tmp[j]);
      }
      printf("%d\n", calc(r, 0, 0, 0) - calc(l-1, 0, 0, 0));
      eval.clear();
    }
  }
  return 0;
}
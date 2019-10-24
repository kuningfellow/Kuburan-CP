#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<stack>

using namespace std;
typedef long long int LL;

int dp1[1005][1005];
LL dp2[1005][1005];
int grid[1005][1005];

stack<pair<int,LL> >st;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", &grid[i][j]);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = m-1; j >= 0; j--) {
        if (j < m-1 && grid[i][j] == grid[i][j + 1]) {
          dp1[i][j] = dp1[i][j + 1] + 1;
        } else {
          dp1[i][j] = 1;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      LL tmp = 0;
      while (!st.empty()) st.pop();
      for (int j = n-1; j >= 0; j--) {
        LL len = 0;
        if (j < n-1 && grid[j+1][i] != grid[j][i]) {
          tmp = 0;
          while (!st.empty()) st.pop();
        }
        while (!st.empty() && st.top().first > dp1[j][i]) {
          tmp -= st.top().first * st.top().second;
          len += st.top().second;
          st.pop();
        }
        len++;
        tmp += len * dp1[j][i];
        st.push(pair<int,LL>(dp1[j][i], len));
        dp2[j][i] = tmp;
      }
    }
    DEBUG(
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          printf("%d ", dp1[i][j]);
        }
        printf("\n");
      }
      printf("\n");
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          printf("%lld ", dp2[i][j]);
        }
        printf("\n");
      }
      printf("\n");
    )
    LL ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans += dp2[i][j];
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
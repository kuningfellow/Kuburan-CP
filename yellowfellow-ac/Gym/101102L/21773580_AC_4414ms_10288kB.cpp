#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

const int maxN = 100005;

int dp[maxN][2][3];  // [n][exist][branchable/has parent]
vector<int>adj[maxN];

int serc(int x, int p, int e, int b) {
  if (dp[x][e][b] != -1) return dp[x][e][b];
  if (adj[x].size() == 0) {
    return 0;
  }
  if (adj[x].size() == 1 && x != p) {
    return dp[x][e][b] = 0;
  }
  dp[x][e][b] = 0;
  if (e == 0) {
    for (auto to : adj[x]) {
      if (to == p) continue;
      dp[x][e][b] += max(serc(to, x, 1, 1), serc(to, x, 0, 0));
    }
  } else {
    for (auto to : adj[x]) {
      if (to == p) continue;
      dp[x][e][b] += max(serc(to, x, 1, 0), serc(to, x, 0, 0));
    }
    if (b) {
      // pick one to continue or stop here
      int tmp = 0;
      vector<pair<int,int>>pick;
      for (auto to : adj[x]) {
        if (to == p) continue;
        pick.push_back(pair<int,int>(serc(to, x, 0, 0) - serc(to, x, 1, 2), to));
        tmp += dp[to][0][0];
      }
      sort(pick.begin(), pick.end());
      if (dp[pick[0].second][1][2] > dp[pick[0].second][0][0]) {
        tmp += dp[pick[0].second][1][2] - dp[pick[0].second][0][0];
      }
      dp[x][e][b] = max(dp[x][e][b], tmp);

      // branch here
      tmp = 0;
      pick.clear();
      for (auto to : adj[x]) {
        if (to == p) continue;
        pick.push_back(pair<int,int>(serc(to, x, 0, 0) - serc(to, x, 1, 0), to));
        tmp += dp[to][0][0];
      }
      sort(pick.begin(), pick.end());
      int req = 3 - (b == 2);
      if (pick.size() >= req) {
        for (int i = 0; i < req; i++) {
          tmp += dp[pick[i].second][1][0] - dp[pick[i].second][0][0];
        }
        dp[x][e][b] = max(dp[x][e][b], tmp + 1);
      }
    }
  }
  DEBUG(printf("at (%d, %d, %d) dp is %d\n", x, e, b, dp[x][e][b]);)
  return dp[x][e][b];
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 3; k++) {
          dp[i][j][k] = -1;
        }
      }
      adj[i].clear();
    }
    for (int i = 1; i < n; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    printf("%d\n", max(serc(1, 1, 1, 1), serc(1, 1, 0, 0)) );
  }
  return 0;
}
 					  		 	 	    	   		      	
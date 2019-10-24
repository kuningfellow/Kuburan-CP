#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int>adj[100005];
int ans = 0, k;
int depth[100005];
int dead[100005];
priority_queue<pair<int,int> >Q;
int init(int x) {
  for (int to : adj[x]) {
    depth[x] = max(init(to) + 1, depth[x]);
  }
  depth[x]++;
  return depth[x];
}
void kill(int x) {
  int targ = -1;
  dead[x] = 1;
  ans++;
  for (int to : adj[x]) {
    if (targ == -1 || depth[to] > depth[targ]) {
      targ = to;
    }
  }
  if (targ != -1) kill(targ);
}

int main() {
  int n;
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; i++) {
    int a;
    scanf("%d", &a);
    adj[a-1].push_back(i);
  }
  init(0);
  for (int i = 0; i < n; i++) {
    Q.push(pair<int,int>(depth[i], i));
  }
  while (k && !Q.empty()) {
    int x = Q.top().second;
    Q.pop();
    if (dead[x]) {
      continue;
    }
    k--;
    kill(x);
  }
  printf("%d\n", ans);
  return 0;
}
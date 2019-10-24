#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

namespace TWOSAT {
  const int maxN = 2400005;
  vector<int>adj[maxN], jda[maxN];
  stack<int>eval;
  int vis[maxN], mark[maxN];
  int N;  // node size without duplicates
  int val;
  int conv(int x, int type) {
    // type: 0=yes, 1=no, 2=Lyes, 3=Lno, 4=Ryes, 5=Rno
    return x + type * N;
  }
  int comp(int x) {
    return x % N + (x/N^1) * N;
  }
  void serc1(int x) {
    if (vis[x]) return;
    vis[x] = 1;
    for (auto to : adj[x]) {
      if (!vis[to]) serc1(to);
    }
    eval.push(x);
  }
  void serc2(int x, int ord) {
    if (vis[x]) return;
    if (vis[comp(x)] == ord) {
      val = 0;
      return;
    }
    vis[x] = ord;
    if (mark[comp(x)] == -1) {
      mark[x] = 1;
    } else mark[x] = mark[comp(x)] ^ 1;
    for (auto to : jda[x]) {
      if (!vis[to]) serc2(to, ord);
    }
  }
  void addedge(int a, int ta, int b, int tb) {    // if a then b
    jda[conv(a, ta)].push_back(conv(b, tb));
    jda[conv(b, tb^1)].push_back(conv(a, ta^1));
    adj[conv(b, tb)].push_back(conv(a, ta));
    adj[conv(a, ta^1)].push_back(conv(b, tb^1));
  }
  void reset() {
    for (int i = 0; i < N*6; i++)
      vis[i] = 0, mark[i] = -1;
  }
  int run() {
    val = 1;
    reset();
    for (int i = 0; i < 6*N; i++) {
      if (!vis[i]) serc1(i);
    }
    reset();
    int ord = 1;
    while (!eval.empty() && val) {
      if (!vis[eval.top()]) {
        serc2(eval.top(), ord++);
      }
      eval.pop();
    }
    return val;
  }
}

struct dat {
  int node, type, x;
  bool operator<(const dat &o) {
    if (x < o.x) return true;
    else if (x > o.x) return false;
    else if (type < o.type) return true;
    return false;
  }
};
int range[400005][2];
vector<dat>proc;
vector<int>ans;

void twosat_init(int n, int p, int M, int m) {
  TWOSAT::N = p;
  for (int i = 0; i < p; i++) {
    TWOSAT::addedge(i, 0, i, 2);
    TWOSAT::addedge(i, 0, i, 4);
  }
}
void complaint_constraints(int n, int p, int M, int m) {
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    TWOSAT::addedge(a-1, 1, b-1, 0);
    TWOSAT::addedge(b-1, 1, a-1, 0);
  }
}
void power_constraints(int n, int p, int M, int m) {
  dat dum;
  for (int i = 0; i < p; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    range[i][0] = l;
    range[i][1] = r;
    if (l > M) {
      TWOSAT::addedge(i, 0, i, 1);
    } else {
      dum.node = i;
      r = min(r, M);
      dum.type = 0, dum.x = l;
      proc.push_back(dum);
      dum.type = 1, dum.x = r;
      proc.push_back(dum);
    }
  }
  sort(proc.begin(), proc.end());
  for (int i = 0, lL = -1, lR = -1; i < proc.size(); i++) {
    if (proc[i].type == 0) {
      if (lL != -1) TWOSAT::addedge(lL, 3, proc[i].node, 3);
      if (lR != -1) {
        TWOSAT::addedge(proc[i].node, 0, lR, 5);
      }
      lL = proc[i].node;
    } else {
      if (lR != -1) TWOSAT::addedge(proc[i].node, 5, lR, 5);
      lR = proc[i].node;
    }
  }
  for (int i = proc.size() - 1, lL = -1, lR = -1; i >= 0; i--) {
    if (proc[i].type == 1) {
      if (lL != -1) {
        TWOSAT::addedge(proc[i].node, 0, lL, 3);
      }
      lR = proc[i].node;
    } else {
      lL = proc[i].node;
    }
  }
}
void interferece_constraints(int n, int p, int M, int m) {
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    TWOSAT::addedge(a-1, 0, b-1, 1);
    TWOSAT::addedge(b-1, 0, a-1, 1);
  }
}

int main() {
  int n, p, M, m;
  scanf("%d %d %d %d", &n, &p, &M, &m);
  twosat_init(n, p, M, m);
  complaint_constraints(n, p, M, m);
  power_constraints(n, p, M, m);
  interferece_constraints(n, p, M, m);
  int val = TWOSAT::run();
  if (!val) {
    printf("-1\n");
  } else {
    int l = 1, r = 1000000;
    for (int i = 0; i < p; i++) {
      if (TWOSAT::mark[i] == 1) {
        l = max(l, range[i][0]);
        r = min(r, range[i][1]);
        ans.push_back(i);
      }
    }
    printf("%d %d\n", ans.size(), l);
    for (int i = 0; i < ans.size(); i++) {
      printf("%d ", ans[i] + 1);
    }
    printf("\n");
  }
  return 0;
}
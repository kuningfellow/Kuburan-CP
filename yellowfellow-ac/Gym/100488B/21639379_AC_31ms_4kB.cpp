#include<stdio.h>
#include<vector>

using namespace std;

int ans[105];
int mark[105];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (n+1)/2; i++) {
    printf("Q %d %d\n", i+1, (n+1)/2+i);
    fflush(stdout);
    vector<int>cur;
    for (int j = 0; j < (n+1)/2; j++) {
      int x;
      scanf("%d", &x);
      cur.push_back(x);
      mark[x] |= 2;
    }
    for (int j = 1; j <= n; j++) {
      if (i && mark[j] == 1) {
        ans[i-1] = j;
      }
      if (i && mark[j] == 2) {
        ans[i+(n+1)/2-1] = j;
      }
      mark[j] = 0;
    }
    for (int j = 0; j < cur.size(); j++) {
      mark[cur[j]] = 1;
    }
  }
  for (int i = 0; i < n; i++) mark[ans[i]] = -1;
  for (int i = 1; i <= n; i++) {
    if (mark[i] == 0) {
      ans[n-1] = i;
    } else if (mark[i] == 1) {
      ans[(n-1)/2] = i;
    }
  }
  printf("A");
  for (int i = 0; i < n; i++) {
    printf(" %d", ans[i]);
  }
  printf("\n");
  fflush(stdout);
  return 0;
}
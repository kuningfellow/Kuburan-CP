#include<stdio.h>
#include<map>

using namespace std;

map<int,int>cnt;
int ar[100005];

int main() {
  int n;
  scanf("%d", &n);
  int val = -1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
    cnt[ar[i]]++;
    if (val == -1 && cnt[ar[i]] == n) val = 0;
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int k, x;
    scanf("%d %d", &k, &x);
    cnt[ar[k]]--;
    if (cnt[ar[k]] == 0) cnt.erase(ar[k]);
    cnt[ar[k] = x]++;
    if (val == -1 && cnt[ar[k]] == n) {
      val = i + 1;
    }
  }
  printf("%d\n", val);
  return 0;
}
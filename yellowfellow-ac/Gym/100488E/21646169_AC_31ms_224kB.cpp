#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

priority_queue<int>pq;
char str[400005];
int cnt[26];

int main() {
  scanf("%s", str);
  for (int i = 0; str[i] != '\0'; i++) {
    cnt[str[i] - 'a']++;
  }
  int sum = 0, maxi = 0;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] > maxi) sum += maxi, maxi = cnt[i];
    else sum += cnt[i];
  }
  if (maxi <= sum && (maxi + sum) % 2 == 0) printf("YES\n");
  else printf("NO\n");
  return 0;
}
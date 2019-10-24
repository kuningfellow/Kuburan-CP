#include<stdio.h>
#include<string.h>

int cons[26][2];
int cnt[100005][26];
int nxt[100005][26];
int last[26];
int cur[26];
char str[100005];
char ans[100005];

int main() {
  int L;
  while (scanf("%s %d", str, &L) != EOF) {
    int l = strlen(str);
    for (int i = 0; i < 26; i++) {
      cnt[l+1][i] = 0;
      cur[i] = 0;
      last[i] = -1;
      scanf("%d %d", &cons[i][0], &cons[i][1]);
    }
    for (int i = l; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
        cnt[i][j] = cnt[i + 1][j];
        nxt[i][j] = last[j];
      }
      if (i > 0) {
        cnt[i][str[i-1] - 'a']++;
        last[str[i-1] - 'a'] = i;
      }
    }
    int ptr = 0;
    for (int i = 0; i <= l && ptr < L;) {
      int can = 0;
      for (int j = 0; j < 26; j++) {
        if (nxt[i][j] == -1) continue;
        int val = 1;
        int debt = 0;
        for (int k = 0; k < 26; k++) {
          if (cur[k] + (k == j) < cons[k][0]) {
            debt += cons[k][0] - cur[k] - (k == j);
          }
          if (!(cons[k][0] <= cur[k] + cnt[nxt[i][j]][k] && cur[k] + (k == j) <= cons[k][1])) {
            val = 0;
            break;
          }
        }
        if (val && debt <= L - ptr - 1) {
          can = 1;
          ans[ptr++] = j + 'a';
          ans[ptr] = '\0';
          cur[j]++;
          i = nxt[i][j];
          break;
        }
      }
      if (!can) break;
    }
    if (ptr != L) printf("-1\n");
    else printf("%s\n", ans);
  }
  return 0;
}
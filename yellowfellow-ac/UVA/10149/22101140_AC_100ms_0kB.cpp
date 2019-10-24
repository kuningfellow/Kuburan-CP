#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>

int ar[13][6];
int seq[13];
int dp[13][1 << 13][64];
int bt[13][1 << 13][64];
int ans[13];

int coba(int type, int x) {
  if (type < 6) {
    return ar[x][type] * (type + 1);
  } else if (type == 6) {
    int ret = 0;
    for (int i = 0; i < 6; i++) {
      ret += (i+1) * ar[x][i];
    }
    return ret;
  } else if (type == 7) {
    int val = 0, ret = 0;
    for (int i = 0; i < 6; i++) {
      if (ar[x][i] >= 3) val = 1;
      ret += (i+1) * ar[x][i];
    }
    return val * ret;
  } else if (type == 8) {
    int val = 0, ret = 0;
    for (int i = 0; i < 6; i++) {
      if (ar[x][i] >= 4) val = 1;
      ret += (i+1) * ar[x][i];
    }
    return val * ret;
  } else if (type == 9) {
    int val = 0, ret = 50;
    for (int i = 0; i < 6; i++) {
      if (ar[x][i] >= 5) val = 1;
    }
    return val * ret;
  } else if (type == 10) {
    if (seq[x] >= 4) return 25;
    return 0;
  } else if (type == 11) {
    if (seq[x] >= 5) return 35;
    return 0;
  } else if (type == 12) {
    int chk = 0;
    for (int i = 0; i < 6; i++) {
      if (ar[x][i] == 3) chk |= 1;
      if (ar[x][i] == 2) chk |= 2;
    }
    if (chk == 3) return 40;
    return 0;
  }
  return 0;
}

int serc(int x, int mask, int bonus) {
  if (bonus > 63) bonus = 63;
  if (x == 13) return bonus >= 63 ? 35 : 0;
  if (dp[x][mask][bonus] != -1) return dp[x][mask][bonus];
  int &ret = dp[x][mask][bonus];
  ret = -1;
  for (int i = 0; i < 13; i++) {
    if (mask & (1 << i)) continue;
    int rec = coba(i, x);
    rec += serc(x+1, mask | (1 << i), bonus + (i<6) * rec);
    if (rec > ret) {
      ret = rec;
      bt[x][mask][bonus] = i;
    }
  }
  return ret;
}

int main() {
  int a;
  while (scanf("%d", &a) != EOF) {
    int in[5];
    for (int k = 0; k < 13; k++) {
      seq[k] = 0;
      for (int i = 0; i < 6; i++) ar[k][i] = 0;
      for (int i = 0; i < 5; i++) {
        if (k == 0 && i == 0) in[i] = a;
        else scanf("%d", &in[i]);
        ar[k][in[i] - 1]++;
      }
      for (int i = 0, sq = 0; i < 6; i++) {
        if (ar[k][i] > 0) sq++;
        else sq = 0;
        if (sq > seq[k]) seq[k] = sq;
      }
      for (int i = 0; i < (1 << 13); i++) {
        for (int j = 0; j < 64; j++) {
          dp[k][i][j] = -1;
        }
      }
      ans[k] = 0;
    }
    serc(0, 0, 0);
    int x = 0, mask = 0, bonus = 0;
    int tot = 0;
    while (x < 13) {
      if (bonus > 63) bonus = 63;
      int t = bt[x][mask][bonus];
      int add = coba(t, x);
      ans[t] = add;
      tot += add;
      x++;
      mask |= (1 << t);
      if (t < 6) bonus += add;
    }
    for (int i = 0; i < 13; i++) {
      printf("%d ", ans[i]);
    }
    if (bonus >= 63) {
      tot += bonus = 35;
    } else {
      bonus = 0;
    }
    printf("%d %d\n", bonus, tot);
  }
  return 0;
}
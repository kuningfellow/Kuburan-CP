#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const LL MOD = 998244353;
LL dp[1005][1005][2];
int n;
int ar[1005];
LL serc(int x, int rem, int st) {
    if (x >= n) {
        if (rem == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (dp[x][rem][st] != -1) {
        return dp[x][rem][st];
    }
    if (x == 0 || ar[x] != ar[x-1]) st = 0;
    dp[x][rem][st] = serc(x + 1, rem, st);
    if (st == 0) {
        dp[x][rem][st] = (dp[x][rem][st] + serc(x + 1, rem - 1, 1)) % MOD;
    }
    return dp[x][rem][st];
}
int main() {
    int k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    sort(ar, ar + n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    printf("%lld\n", serc(0, k, 0));
}

#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const LL MOD = 1000000009;

pair<LL,LL> dp[130][1005];
int k;
pair<LL,LL> serc(int x, int rem) {
    if (x == 0) {
        if (rem == 0) return pair<LL,LL>(0ll, 1ll);
        return pair<LL,LL>(0ll, 0ll);
    }
    if (dp[x][rem].first != -1) {
        return dp[x][rem];
    }
    dp[x][rem].first = dp[x][rem].second = 0;
    pair<LL,LL> ret = serc(x-1, (rem*2+1) % k);
    if (ret.second > 0) {
        dp[x][rem].first = (dp[x][rem].first + ret.second + ret.first) % MOD;
        dp[x][rem].second = (dp[x][rem].second + ret.second) % MOD;
    }
    ret = serc(x-1, (rem*2) % k);
    if (ret.second > 0) {
        dp[x][rem].first = (dp[x][rem].first + ret.first) % MOD;
        dp[x][rem].second = (dp[x][rem].second + ret.second) % MOD;
    }
    return dp[x][rem];

}

int main() {
    int b;
    scanf("%d %d", &k, &b);
    for (int i = 0; i < 130; i++) {
        for (int j = 0; j < 1005; j++) {
            dp[i][j].first = -1;
        }
    }
    printf("%lld\n", serc(b, 0).first);
}

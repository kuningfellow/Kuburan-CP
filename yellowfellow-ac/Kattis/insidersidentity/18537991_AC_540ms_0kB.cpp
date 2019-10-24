//Kattis Insider's Identity
//ICPC 2019 Regional Hanoi
//non backtrack build + auto break when valid
#include<stdio.h>
#include<queue>
using namespace std;
char str[35];
namespace aho {
    int nxt[1000005][2];
    int kmp[1000005], sl[1000005], mark[1000005];
    int gptr;
    void reset() {
        gptr = 0;
        for (int i = 0; i < 1000005; i++) {
            nxt[i][0] = nxt[i][1] = -1;
            kmp[i] = sl[i] = mark[i] = 0;
        }
    }
    void fill(int x, int ptr) {
        if (str[x] == '\0') {
            mark[ptr] = 1;
            return;
        }
        if (str[x] == '1' || str[x] == '*') {
            if (nxt[ptr][1] == -1) nxt[ptr][1] = ++gptr;
            fill(x + 1, nxt[ptr][1]);
        }
        if (str[x] == '*') {
            if (nxt[ptr][0] == -1) nxt[ptr][0] = ++gptr;
            fill(x + 1, nxt[ptr][0]);
        }
    }
    void build() {
        queue<int> q;
        if (nxt[0][0] != -1) q.push(nxt[0][0]);
        if (nxt[0][1] != -1) q.push(nxt[0][1]);
        while (!q.empty()) {
            int siz = q.size();
            for (int i = 0; i < siz; i++) {
                int x = q.front();
                q.pop();
                for (int j = 0; j < 2; j++) {
                    if (nxt[x][j] != -1) {
                        int k = kmp[x];
                        while (k != 0 && nxt[k][j] == -1) k = kmp[k];
                        if (nxt[k][j] != -1) k = nxt[k][j];
                        kmp[nxt[x][j]] = k;
                        sl[nxt[x][j]] = mark[k] ? k : sl[k];
                        q.push(nxt[x][j]);
                    }
                }
            }
        }
    }
}

long long int dp[51][1000005];
class solution {
private:
    int n;
    long long int serc(int x, int p) {
        if (x == 0) {
            while (p != 0) {
                if (aho::mark[p]) return 1;
                p = aho::sl[p];
            }
            return 0;
        }
        if (dp[x][p] != -1) return dp[x][p];
        dp[x][p] = 0;
        
        int j = p;
        while (j && aho::nxt[j][1] == -1) j = aho::kmp[j];
        if (aho::nxt[j][1] != -1) j = aho::nxt[j][1];
        int tmp = j;
        int con = 0;
        while (!con && tmp) {
            if (aho::mark[tmp]) con = 1;
            tmp = aho::sl[tmp];
        }
        if (con) dp[x][p] += (1ll << (x - 1));
        else dp[x][p] += serc(x - 1, j);
        
        j = p;
        while (j && aho::nxt[j][0] == -1) j = aho::kmp[j];
        if (aho::nxt[j][0] != -1) j = aho::nxt[j][0];
        con = 0;
        tmp = j;
        while (!con && tmp) {
            if (aho::mark[tmp]) con = 1;
            tmp = aho::sl[tmp];
        }
        if (con) dp[x][p] += (1ll << (x - 1));
        else dp[x][p] += serc(x - 1, j);
        
        return dp[x][p];
    }
public:
    solution() {
        scanf("%d", &n);
        scanf("%s", str);
        aho::reset();
        aho::fill(0, 0);
        aho::build();
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= aho::gptr; j++) {
                dp[i][j] = -1;
            }
        }
        printf("%lld\n", serc(n, 0));
    }
};

int main() {
    solution();
    return 0;
}
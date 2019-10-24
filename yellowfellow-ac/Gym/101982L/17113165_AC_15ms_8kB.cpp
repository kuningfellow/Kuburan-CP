#include<bits/stdc++.h>
using namespace std;
int cnt[1005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        cnt[a]++;
        cnt[b+1]--;
    }
    int car = 0;
    for (int i = 0; i < 1005; i++) {
        car += cnt[i];
        cnt[i] = car;
    }
    int ans = -1;
    for (int i = 0; i < 1005; i++) {
        if (cnt[i] == i) ans = i;
    }
    printf("%d\n", ans);
}

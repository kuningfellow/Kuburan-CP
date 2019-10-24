#include<bits/stdc++.h>
using namespace std;
char str[1005];
char str2[1005];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        maxi = max(maxi, a);
    }
    maxi *= k;
    if (maxi % 1000 > 0) {
        maxi = maxi/1000*1000 + 1000;
    }
    printf("%d\n", maxi/1000);
    return 0;
}

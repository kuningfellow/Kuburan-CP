#include<bits/stdc++.h>
using namespace std;
char str[1005];
char str2[1005];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    scanf("%s", str2);
    int l = strlen(str);
    int ans = 0;
    int ans2 = 0;
    for (int i = 0; i < l; i++) {
        if (str[i] == str2[i]) ans++;
    }
    ans2 = min(ans, n) + l - max(n, ans);
    printf("%d\n", ans2);
}

#include<bits/stdc++.h>
using namespace std;
int cnt[2000];
int n;
int idx=1;
int check=1;
void dfs(int x) {
    while(cnt[x]>0){
        if(idx>n){
            check=0;
            return;
        }
        idx++;
        cnt[x]--;
        cnt[idx]--;
        dfs(idx);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cnt[i]);
    }
    dfs(1);
    if(idx==n&&check)cout<<"YES";
    else cout<<"NO";
}

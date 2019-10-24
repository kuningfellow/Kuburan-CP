#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int serc(int x, int n){
    if (x==1){
        return 1;
    }
    if (dp[n][x]!=-1){
        return dp[n][x];
    }
    dp[n][x]=0;
    for (int i=0;i<=n;i++){
        dp[n][x]+=serc(x-1,n-i);
        dp[n][x]%=1000000;
    }
    return dp[n][x];
}
int main(){
    while (1<2){
        int a,b;
        cin>>a>>b;
        if (a==0&&b==0)break;
        for (int i=0;i<=a;i++){
            for (int j=0;j<=b;j++){
                dp[i][j]=-1;
            }
        }
        printf ("%d\n",serc(b,a));
    }
}

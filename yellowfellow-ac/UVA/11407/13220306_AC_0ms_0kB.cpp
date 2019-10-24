#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int serc(int x){
    if (x==0){
        return dp[x]=0;
    }
    int ret=100000;
    if (dp[x]!=-1){
        return dp[x];
    }
    for (int i=1;i*i<=x;i++){
        ret=min(ret,1+serc(x-i*i));
    }
    return dp[x]=ret;
}
int main(){
    int tc;
    for (int i=0;i<=10000;i++){
        dp[i]=-1;
    }
    serc(10000);
    cin>>tc;
    while (tc--){
        int n;
        cin>>n;
        printf ("%d\n",dp[n]);
    }
}

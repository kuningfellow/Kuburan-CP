#include <bits/stdc++.h>
using namespace std;
long long int dp[10005];
int n;
long long int ar[10005];
long long int serc(int x){
    if (x>=n)return 0;
    if (dp[x]!=-1)return dp[x];
    return dp[x]=max(serc(x+1),ar[x]+serc(x+2));
}
int main(){
    int tc,kas=1;
    cin>>tc;
    while (tc--){
        cin>>n;
        for (int i=0;i<n;i++){
            dp[i]=-1;
            cin>>ar[i];
        }
        printf ("Case %d: %lld\n",kas++,serc(0));
    }
}

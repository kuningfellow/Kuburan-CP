#include <bits/stdc++.h>
using namespace std;
long long int cost[8005];
long long int dp[805][8005];
void serc(int l, int r, int lcut, int rcut, int k){
    if (l>r)return;
    int mid=(l+r)/2;
    int div=-1;
    long long int best=(1ll<<62);
    int cap=min(mid,rcut);
    for (int i=lcut;i<=cap;i++){
        if (dp[k-1][i-1]+(cost[mid]-cost[i-1])*(mid-i+1)<best){
            best=dp[k-1][i-1]+(cost[mid]-cost[i-1])*(mid-i+1);
            div=i;
        }
    }
    dp[k][mid]=best;
    serc(l,mid-1,lcut,div,k);
    serc(mid+1,r,div,rcut,k);
}
int main(){
    int n,m;
    cin>>n>>m;
    cost[0]=0;
    for (int i=0;i<n;i++){
        scanf("%lld",&cost[i+1]);
    }
    for (int i=1;i<=n;i++){
        cost[i]+=cost[i-1];
    }
    dp[1][0]=0;
    for (int i=1;i<=n;i++){
        dp[1][i]=cost[i]*i;
    }
    for (int i=2;i<=m;i++){
        serc(1,n,1,n,i);
    }
    printf ("%lld\n",dp[m][n]);
}
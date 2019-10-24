#include <bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int ar[2005][2];
int serc(int x, int c){
    if (c<0)return -(1<<30);
    if (x==0){
        return 0;
    }
    if (dp[x][c]!=-1)
        return dp[x][c];
    return dp[x][c]=max(ar[x][1]+serc(x-1,c-ar[x][0]),serc(x-1,c));
}
int main(){
    int x,n;
    for (int i=0;i<2005;i++){
        for (int j=0;j<2005;j++){
            dp[i][j]=-1;
        }
    }
    cin>>x>>n;
    for (int i=1;i<=n;i++){
        cin>>ar[i][0]>>ar[i][1];
    }
    printf ("%d\n",serc(n,x));
}

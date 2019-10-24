#include <bits/stdc++.h>
using namespace std;
long long int dp[1005][1005];
long long int ar[1005];
long long int br[1005];
int n,m;
long long int serc(int x, int y){
    if (x<0||y<0){
        return (1<<30);
    }
    if(x==0&&y==0){
        return 0;
    }
    if (dp[x][y]!=-1){
        return dp[x][y];
    }
    return dp[x][y]=min((m-y)*ar[x]+serc(x-1,y),(n-x)*br[y]+serc(x,y-1));
}
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        cin>>n>>m;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                dp[i][j]=-1;
            }
        }
        for (int i=1;i<n;i++){
            cin>>ar[i];
        }
        for (int i=1;i<m;i++){
            cin>>br[i];
        }
        sort(ar+1,ar+n);
        sort(br+1,br+m);
        printf ("%lld\n",serc(n-1,m-1));
    }
}

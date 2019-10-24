#include <bits/stdc++.h>
using namespace std;
int ar[55];
int n;
int dp[1005][1005];
int serc(int l, int r){
    if (dp[l][r]!=-1){
        return dp[l][r];
    }
    int fou=0;
    int ret=(1<<29);
    for (int i=0;i<n;i++){
        if (ar[i]>l&&ar[i]<r){
            fou=1;
            ret=min(ret,serc(l,ar[i])+serc(ar[i],r));
        }
    }
    if (fou==0)return dp[l][r]=0;
    else return dp[l][r]=ret+r-l;
}
int main(){
    while (1<2){
        for (int i=0;i<1005;i++){
            for (int j=0;j<1005;j++){
                dp[i][j]=-1;
            }
        }
        int l;
        cin>>l;
        if (l==0)break;
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>ar[i];
        }
        printf ("The minimum cutting is %d.\n",serc(0,l));
    }
}

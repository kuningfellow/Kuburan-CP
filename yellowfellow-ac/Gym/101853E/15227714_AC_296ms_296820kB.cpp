#include<bits/stdc++.h>
using namespace std;
int dp[17][17][(1<<18)];
int ar[17][17];
int n;
int serc(int x, int y, int mask){
    mask=(mask&((1<<(n+1))-1));
    if (y==n){
        x++;
        y=0;
    }
    if (x==n){
        return 0;
    }
    if (dp[x][y][mask]!=-1){
        return dp[x][y][mask];
    }
    int ret=0;
    int misk=mask<<1;
    ret=max(ret,serc(x,y+1,misk));
    misk=mask;
    int good=1;
    if ((misk&(1<<(n-1)))==0){
        good=min(good,1);
    }
    else good=0;
    if (y>0&&(misk&1)==0&&(misk&(1<<n))==0){
        good=min(good,1);
    }
    else if (y>0)good=0;
    if (y+1<n&&(misk&(1<<(n-2)))==0){
        good=min(good,1);
    }
    else if (y+1<n)good=0;
    if (good==1){
        misk<<=1;
        misk|=1;
        ret=max(ret,ar[x][y]+serc(x,y+1,misk));
    }
    return dp[x][y][mask]=ret;
}
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        cin>>n;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                scanf("%d",&ar[i][j]);
                for (int k=0;k<(1<<(n+1));k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        printf ("%d\n",serc(0,0,0));
    }
}
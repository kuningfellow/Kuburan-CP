//UVA 10086 Test the Rods
#include<bits/stdc++.h>
using namespace std;
int dp[31][301][301];
int bt[31][301][301];
vector<int>ar[31];
vector<int>br[31];
int n;
int serc(int x, int l, int r){
    if (x==n){
        return 0;
    }
    if (dp[x][l][r]!=-1){
        return dp[x][l][r];
    }
    int rat=(1<<30);
    int ret;
    for (int i=0;i<ar[x].size();i++){
        int s=ar[x].size()-1;
        if (l>=i&&r>=s-i){
            ret=ar[x][i]+br[x][s-i]+serc(x+1,l-i,r-(s-i));
            if (ret<rat){
                rat=ret;
                bt[x][l][r]=i;
            }
        }
    }
    return dp[x][l][r]=rat;
}
int main(){
    while (1<2){
        int l,r;
        cin>>l>>r;
        if (l==0&&r==0)break;
        cin>>n;
        for (int i=0;i<n;i++){
            for (int j=0;j<=l;j++){
                for (int k=0;k<=r;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        for (int i=0;i<n;i++){
            ar[i].clear();
            br[i].clear();
            int a,b;
            cin>>a;
            ar[i].push_back(0);
            br[i].push_back(0);
            for (int j=0;j<a;j++){
                cin>>b;
                ar[i].push_back(b);
            }
            for (int j=0;j<a;j++){
                cin>>b;
                br[i].push_back(b);
            }
        }
        printf ("%d\n",serc(0,l,r));
        int x=0;
        while (x<n){
            int red=bt[x][l][r];
            if (x>0)printf (" ");
            printf ("%d",red);
            l-=red;
            r-=ar[x].size()-1-red;
            x++;
        }
        printf ("\n\n");
    }
}
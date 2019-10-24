#include <bits/stdc++.h>
using namespace std;
int ar[105][105];
int vis[105][105];
int r,c;
int val;
int fin(int x, int y, int l){
    if (x==0||y==0||x==r-1||y==c-1){
        val=0;
    }
    vis[x][y]=1;
    int ret=1;
    if (x+1<r&&vis[x+1][y]==0&&ar[x+1][y]<l){
        ret+=fin(x+1,y,l);
    }
    if (x-1>=0&&vis[x-1][y]==0&&ar[x-1][y]<l){
        ret+=fin(x-1,y,l);
    }
    if (y+1<c&&vis[x][y+1]==0&&ar[x][y+1]<l){
        ret+=fin(x,y+1,l);
    }
    if (y-1>=0&&vis[x][y-1]==0&&ar[x][y-1]<l){
        ret+=fin(x,y-1,l);
    }
    return ret;
}
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        cin>>r>>c;
        int maxi=0;
        int mini=(1<<30);
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                cin>>ar[i][j];
                if (ar[i][j]>maxi)maxi=ar[i][j];
                if (ar[i][j]<mini)mini=ar[i][j];
            }
        }
        int ans=0;
        for (int i=mini+1;i<maxi;i++){
            for (int j=0;j<r;j++){
                for (int k=0;k<c;k++){
                    vis[j][k]=0;
                }
            }
            for (int j=0;j<r;j++){
                for (int k=0;k<c;k++){
                    if (vis[j][k]==0&&ar[j][k]<i){
                        val=1;
                        int temp=fin(j,k,i);
                        if (val==1){
                            ans+=temp;
                        }
                    }
                }
            }
        }
        printf ("%d\n",ans);
    }
}

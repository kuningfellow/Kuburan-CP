#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    scanf("%d",&tc);
    while (tc--){
        int rec;
        scanf("%d",&rec);
        int n;
        scanf("%d",&n);
        int vis[10005];
        for (int i=0;i<10005;i++){
            vis[i]=(1<<30);
        }
        int m;
        vis[0]=0;
        for (int i=0;i<n;i++){
            scanf("%d",&m);
            for (int j=10005;j>=0;j--){
                if (j-m>=0&&vis[j]>vis[j-m]+1){
                    vis[j]=vis[j-m]+1;
                }
            }
        }
        for (int i=rec;i<10005;i++){
            if (vis[i]!=(1<<30)){
                printf ("%d %d\n",i,vis[i]);
                break;
            }
        }
    }
}
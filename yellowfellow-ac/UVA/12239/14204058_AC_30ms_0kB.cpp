//UVA 12239 Bingo!
#include <bits/stdc++.h>
using namespace std;
int abso(int x){
    if (x<0)return -x;
    return x;
}
int main(){
    while (1<2){
        int n,b;
        scanf("%d%d",&n,&b);
        if (n==0&&b==0)break;
        int vis[n+1];
        for (int i=0;i<=n;i++){
            vis[i]=0;
        }
        for (int i=0;i<b;i++){
            int a;
            scanf("%d",&a);
            vis[a]=1;
        }
        for (int i=0;i<=n;i++){
            if ((vis[i]&1)==0)continue;
            for (int j=0;j<=n;j++){
                if ((vis[j]&1)==0)continue;
                vis[abso(i-j)]|=2;
            }
        }
        int all=1;
        for (int i=0;i<=n;i++){
            if ((vis[i]&2)==0){
                all=0;
                break;
            }
        }
        if (all==1)printf ("Y\n");
        else printf ("N\n");
    }
}
#include <bits/stdc++.h>
using namespace std;
char rem[1005][1005];
int n,m;
int vis[1005][1005];
int res[1000005];
int siz=0;
int serc(int x, int y, int nu){
    if (rem[x][y]=='*')
        return 1;
    vis[x][y]=nu;
    int ret=0;
    if (x+1<n&&vis[x+1][y]!=nu){
        ret+=serc(x+1,y,nu);
    }
    if (x-1>=0&&vis[x-1][y]!=nu){
        ret+=serc(x-1,y,nu);
    }
    if (y+1<m&&vis[x][y+1]!=nu){
        ret+=serc(x,y+1,nu);
    }
    if (y-1>=0&&vis[x][y-1]!=nu){
        ret+=serc(x,y-1,nu);
    }
    return ret;
}
int main(){
    int k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<n;i++){
        scanf("%s",rem[i]);
    }
    for (int i=0;i<k;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        if (vis[a][b]==0){
            res[i]=serc(a,b,i+1);
        }
        printf ("%d\n",res[vis[a][b]-1]);
    }
}

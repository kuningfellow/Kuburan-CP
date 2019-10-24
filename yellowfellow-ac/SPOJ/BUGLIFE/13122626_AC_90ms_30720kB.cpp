#include <bits/stdc++.h>
using namespace std;
int vis[2005];
int con[2005][2005];
int n;
int yes;
void col(int x, int c){
    vis[x]=c;
    for (int i=0;i<n;i++){
        if (vis[i]==c&&con[x][i]==1){
            yes=0;
            break;
        }
        if (vis[i]==-1&&con[x][i]==1){
            col(i,c^1);
        }
    }
}
int main(){
    int tc,kas=1;
    cin>>tc;
    while (tc--){
        int m;
        cin>>n>>m;
        int a,b;
        for (int i=0;i<n;i++){
            vis[i]=-1;
            for (int j=0;j<n;j++){
                con[i][j]=0;
            }
        }
        yes=1;
        for (int i=0;i<m;i++){
            cin>>a>>b;
            a--;
            b--;
            con[a][b]=1;
            con[b][a]=1;
        }
        for (int i=0;i<n;i++){
            if (vis[i]==-1){
                col(i,0);
            }
            if (yes==0)break;
        }
        printf ("Scenario #%d:\n",kas++);
        if (yes==0)printf ("Suspicious bugs found!\n");
        else printf ("No suspicious bugs found!\n");
    }
}

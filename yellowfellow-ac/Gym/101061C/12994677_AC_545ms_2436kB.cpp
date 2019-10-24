#include <bits/stdc++.h>
using namespace std;
vector<int>con[105][3];
int vis[105];
int tot[105];
int main(){
    int tc;
    scanf("%d",&tc);
    while (tc--){
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=0;i<=n;i++){
            con[i][0].clear();
            con[i][1].clear();
            con[i][2].clear();
        }
        int a,b,c,d;
        for (int i=0;i<m;i++){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            con[a][0].push_back(b);
            con[a][1].push_back(c);
            con[a][2].push_back(d);
            con[b][0].push_back(a);
            con[b][1].push_back(c);
            con[b][2].push_back(d);
        }
        for (int i=0;i<=n;i++){
            vis[i]=(1<<30);
            tot[i]=0;
        }
        int x,y;
        scanf("%d%d",&x,&y);
        vis[x]=0;
        tot[x]=0;
        for (int i=0;i<n-1;i++){
            for (int j=1;j<=n;j++){
                for (int k=0;k<con[j][0].size();k++){
                    a=0;
                    if (con[j][2][k]==1){
                        a=con[j][1][k];
                    }
                    if (vis[j]!=(1<<30)&&vis[con[j][0][k]]>=vis[j]+a){
                        if (vis[con[j][0][k]]>vis[j]+a||tot[con[j][0][k]]>tot[j]+con[j][1][k]){
                            vis[con[j][0][k]]=vis[j]+a;
                            tot[con[j][0][k]]=tot[j]+con[j][1][k];
                        }
                    }
                }
            }
        }
        if (vis[y]==(1<<30))
            printf ("-1\n");
        else printf ("%d %d\n",vis[y],tot[y]);
    }
}

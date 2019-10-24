#include <bits/stdc++.h>
using namespace std;
int vis[205];
vector<int>lis[205];
int yes=1;
void col(int x,int c, int s){
    vis[x]=c+s;
    for (int i=0;i<lis[x].size();i++){
        if (vis[lis[x][i]]==vis[x]){
            yes=0;
            break;
        }
        if (vis[lis[x][i]]==-1){
            col(lis[x][i],c^1,s);
        }
    }
}
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int n,m;
        cin>>n>>m;
        for (int i=0;i<n;i++){
            vis[i]=-1;
            lis[i].clear();
        }
        int a,b;
        for (int i=0;i<m;i++){
            cin>>a>>b;
            lis[a].push_back(b);
            lis[b].push_back(a);
        }
        int s=2;
        int ans=0;
        for (int i=0;i<n;i++){
            if (vis[i]==-1){
                yes=1;
                col(i,0,s);
                if (yes==0){
                    ans=-1;
                    break;
                }
                a=0;
                b=0;
                for (int j=0;j<n;j++){
                    if (vis[j]==s){
                        a++;
                    }
                    if (vis[j]==s+1){
                        b++;
                    }
                }
                if (a==0)a=1;
                if (b==0)b=1;
                s*=2;
                ans+=min(a,b);
            }
        }
        printf ("%d\n",ans);
    }
}

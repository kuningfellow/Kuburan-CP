#include <bits/stdc++.h>
using namespace std;
int main(){
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    queue<int>q;
    q.push(s);
    int vis[f+1];
    for (int i=1;i<=f;i++){
        vis[i]=(1<<30);
    }
    vis[s]=1;
    for (int i=1;i<=f;i++){
        if (i-u>0)
        vis[i]=min(vis[i],vis[i-u]+1);
    }
    for (int i=f;i>0;i--){
        if (i+d<=f)
            vis[i]=min(vis[i],vis[i+d]+1);
    }
    for (int i=1;i<=f;i++){
        if (i-u>0)
        vis[i]=min(vis[i],vis[i-u]+1);
    }
    if (vis[g]!=(1<<30))
        printf ("%d\n",vis[g]-1);
    else printf ("use the stairs\n");
}

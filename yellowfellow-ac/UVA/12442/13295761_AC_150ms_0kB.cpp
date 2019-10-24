#include <bits/stdc++.h>
using namespace std;
int num[50005];
int low[50005];
int vis[50005];
int comp[50005];
int par[50005];
int dead[50005];
int coun;
stack<int>stak;
vector<int>lis[50005];
void tarj(int x){
    vis[x]=1;
    num[x]=low[x]=coun++;
    stak.push(x);
    for (int i=0; i<lis[x].size();i++){
        if (num[lis[x][i]]==0){
            tarj(lis[x][i]);
        }
        if (vis[lis[x][i]]==1){
            low[x]=min(low[x],low[lis[x][i]]);
        }
    }
    if (num[x]==low[x]){
        int v;
        while (1<2){
            v=stak.top();
            par[v]=x;
            comp[x]++;
            stak.pop();
            vis[v]=0;
            if (v==x)break;
        }
        if (comp[x]>1){
            dead[x]=1;
        }
        // printf ("here %d\n",comp[x]);
    }
}
void serc(int x){
    vis[x]=1;
    if (dead[x]==1){
        return;
    }
    int ret=0;
    for (int i=0;i<lis[x].size();i++){
        if (vis[par[lis[x][i]]]==0){
            serc(par[lis[x][i]]);
        }
        if (vis[par[lis[x][i]]]==1){
            ret+=comp[par[lis[x][i]]];
        }
    }
    comp[x]+=ret;
}
int main(){
    int tc,kas=1;
    cin>>tc;
    while (tc--){
        int n,a,b;
        cin>>n;
        for (int i=0;i<=n;i++){
            vis[i]=0;
            num[i]=0;
            par[i]=i;
            low[i]=(1<<30);
            lis[i].clear();
            comp[i]=0;
            dead[i]=0;
        }
        coun=1;
        for (int i=0;i<n;i++){
            cin>>a>>b;
            lis[a].push_back(b);
        }
        for (int i=1;i<=n;i++){
            if (num[i]==0){
                tarj(i);
            }
        }
        int maxi=0;
        int ans=0;
        for (int i=1;i<=n;i++){
            if (vis[par[i]]==0){
                serc(par[i]);
            }
            int temp=comp[par[i]];
            if (temp>maxi||(temp==maxi&&par[i]<ans)){
                maxi=temp;
                ans=par[i];
            }
        }
        printf ("Case %d: %d\n",kas++,ans);
        // for (int i=1;i<=n;i++){
        //     printf ("node %d has %d components\n",i,comp[i]);
        // }
    }
}
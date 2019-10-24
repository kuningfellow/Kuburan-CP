#include <bits/stdc++.h>
using namespace std;
int par[105];
int finpar(int x){
    if (par[x]==x)return x;
    return par[x]=finpar(par[x]);
}
struct data{
    int cost;
    int a;
    int b;
    bool operator < (data other){
        return cost>other.cost;
    }
};
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int tc,kas=1;
    cin>>tc;
    while (tc--){
        int n,m;
        cin>>n>>m;
        struct data dat[m];
        for (int i=0;i<n;i++){
            par[i]=i;
        }
        for (int i=0;i<m;i++){
            cin>>dat[i].a>>dat[i].b>>dat[i].cost;
        }
        sort(dat,dat+m);
        int ans=(1<<30);
        for (int i=0;i<m;i++){
            if (finpar(dat[i].a)!=finpar(dat[i].b)){
                par[finpar(dat[i].a)]=finpar(dat[i].b);
                ans=dat[i].cost;
            }
        }
        printf ("Case #%d: %d\n",kas++,ans);
    }
}
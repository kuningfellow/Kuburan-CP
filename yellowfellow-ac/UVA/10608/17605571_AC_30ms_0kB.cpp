#include <bits/stdc++.h>
using namespace std;
int par[30005];
int siz[30005];
int finpar(int x){
    if (par[x]==x)return x;
    return par[x]=finpar(par[x]);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int tc;
    cin>>tc;
    while (tc--){
        int n,m;
        cin>>n>>m;
        for (int i=0;i<n;i++){
            par[i]=i;
            siz[i]=0;
        }
        int a,b;
        int maxi=0;
        for (int i=0;i<m;i++){
            cin>>a>>b;
            a--;
            b--;
            if (finpar(a)!=finpar(b)){
                par[finpar(a)]=finpar(b);
            }
        }
        for (int i=0;i<n;i++){
            siz[par[finpar(i)]]++;
            maxi=max(siz[par[finpar(i)]],maxi);
        }
        printf ("%d\n",maxi);
    }
}
#include <bits/stdc++.h>
using namespace std;
int par[200005];
int finpar(int x){
    if (par[x]==x)return x;
    return par[x]=finpar(par[x]);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    while (1<2){
        int n,m,a,b,c;
        scanf("%d%d",&n,&m);
        if (n==0&&m==0)break;
        for (int i=0;i<=n;i++){
            par[i]=i;
        }
        vector<pair<int,pair<int,int> > >lis;
        int red=0;
        for (int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            red+=c;
            lis.push_back(pair<int,pair<int,int> >(c,pair<int,int>(a,b)));
        }
        sort(lis.begin(),lis.end());
        int tot=0;
        int cnt=0;
        for (int i=0;i<m;i++){
            if (finpar(lis[i].second.first)!=finpar(lis[i].second.second)){
                tot+=lis[i].first;
                cnt++;
                par[finpar(lis[i].second.first)]=finpar(lis[i].second.second);
            }
        }
        printf ("%d\n",red-tot);
    }
}
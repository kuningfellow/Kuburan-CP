#include <bits/stdc++.h>
using namespace std;
int par[500005];
int coun[500005];
int finpar(int x){
    if (par[x]==x)return x;
    return par[x]=finpar(par[x]);
}
int merge(int a, int b){
    int x=finpar(a);
    int y=finpar(b);
    if (x!=y){
        coun[x]+=coun[y];
        coun[y]=0;
        par[y]=x;
    }
}
int main(){
    int n;
    cin>>n;
    for (int i=0;i<500005;i++){
        par[i]=i;
        coun[i]=1;
    }
    int cnt=0;
    map<int,int>take;
    for (int i=0;i<n;i++){
        int a,b;
        cin>>a;
        vector<int>lis;
        int tot=0;
        for (int j=0;j<a;j++){
            cin>>b;
            lis.push_back(b);
        }
        for (int j=0;j<a;j++){
            if (take[finpar(lis[j])]==0)
                tot+=coun[finpar(lis[j])];
            take[finpar(lis[j])]=1;
        }
        take.clear();
        if (tot==a){
            cnt++;
            for (int j=1;j<a;j++){
                merge(lis[0],lis[j]);
            }
        }
    }
    printf ("%d\n",cnt);
}
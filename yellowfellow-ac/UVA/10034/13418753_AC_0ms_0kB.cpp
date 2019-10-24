#include <bits/stdc++.h>
using namespace std;
int par[105];
int finpar(int x){
    if (par[x]==x)return x;
    return par[x]=finpar(par[x]);
}
double point[105][2];
double dist(int a, int b){
    double ta=point[a][0]-point[b][0];
    ta*=ta;
    double tb=point[a][1]-point[b][1];
    tb*=tb;
    return sqrt(ta+tb);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int tc;
    cin>>tc;
    while (tc--){
        int n;
        cin>>n;
        for (int i=0;i<n;i++){
            par[i]=i;
            cin>>point[i][0]>>point[i][1];
        }
        vector<pair<double,pair<int,int> > >lis;
        for (int i=0;i<n-1;i++){
            for (int j=i+1;j<n;j++){
                lis.push_back(pair<double,pair<int,int> >(dist(i,j),pair<int,int>(i,j)));
            }
        }
        double tot=0;
        sort(lis.begin(),lis.end());
        for (int i=0;i<lis.size();i++){
            if (finpar(lis[i].second.first)!=finpar(lis[i].second.second)){
                tot+=lis[i].first;
                par[finpar(lis[i].second.first)]=finpar(lis[i].second.second);
            }
        }
        printf ("%.2f\n",tot);
        if (tc!=0)printf ("\n");
    }
}
#include <bits/stdc++.h>
using namespace std;
int par[505];
int point[505][2];
int finpar(int x){
    if (par[x]==x)return x;
    return par[x]=finpar(par[x]);
}
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
        int s,n;
        cin>>s>>n;
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
        double maxi=0;
        int c=n-s;
        sort(lis.begin(),lis.end());
        for (int i=0;i<lis.size()&&c>0;i++){
            if (finpar(lis[i].second.first)!=finpar(lis[i].second.second)){
                maxi=lis[i].first;
                par[finpar(lis[i].second.first)]=finpar(lis[i].second.second);
                c--;
            }
        }
        printf ("%.2f\n",maxi);
    }
}
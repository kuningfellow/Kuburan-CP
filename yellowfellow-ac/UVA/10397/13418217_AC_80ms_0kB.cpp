#include <bits/stdc++.h>
using namespace std;
int par[751];
int ar[751][2];
int finpar(int p){
    if (par[p]==p)return p;
    return par[p]=finpar(par[p]);
}
double dis(int i, int j){
    double a=ar[i][0]-ar[j][0];
    double b=ar[i][1]-ar[j][1];
    return sqrt(a*a+b*b);
}
vector<pair<double,pair<int,int> > >con;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    while (scanf("%d",&n)!=EOF){
        for (int i=0;i<n;i++){
            par[i]=i;
            cin>>ar[i][0]>>ar[i][1];
        }
        for (int i=0;i<n-1;i++){
            for (int j=i+1;j<n;j++){
                con.push_back(pair<double,pair<int,int> >(dis(i,j),pair<int,int>(i,j)));
            }
        }
        int m;
        cin>>m;
        int a,b;
        for (int i=0;i<m;i++){
            cin>>a>>b;
            con.push_back(pair<double,pair<int,int> >(0,pair<int,int>(a-1,b-1)));
        }
        sort(con.begin(),con.end());
        int l=con.size();
        double d=0;
        for (int i=0;i<l;i++){
            if (finpar(con[i].second.first)!=finpar(con[i].second.second)){
                par[finpar(con[i].second.first)]=finpar(con[i].second.second);
                d+=con[i].first;
            }
        }
        printf ("%.2f\n",d);
        con.clear();
    }
}
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>lis;
void ham(int x, int t){
    if (x==n){
        if (t==m){
            for (int i=0;i<lis.size();i++){
                printf ("%d",lis[i]);
            }
            printf ("\n");
        }
        return;
    }
    lis.push_back(0);
    ham(x+1,t);
    lis.pop_back();
    lis.push_back(1);
    ham(x+1,t+1);
    lis.pop_back();
    return;
}
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        cin>>n>>m;
        ham(0,0);
        if (tc>0)printf ("\n");
    }
}

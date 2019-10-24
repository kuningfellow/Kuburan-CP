#include <bits/stdc++.h>
using namespace std;
map<string,int>m;
int main(){
    int n;
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++){
        string x,y;
        cin>>x>>y;
        if(cnt<12)
            if(m[x]==0){
                cnt++;
                m[x]++;
                cout<<x<<" "<<y<<endl;
            }
    }

}

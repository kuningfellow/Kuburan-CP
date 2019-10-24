#include <bits/stdc++.h>
using namespace std;
int main(){
    map<string,int>mark;
    int n;
    cin>>n;
    string rem;
    for (int i=0;i<n;i++){
        cin>>rem;
        if (mark[rem]==0){
            printf ("OK\n");
        }
        else{
            cout<<rem<<mark[rem]<<endl;
        }
        mark[rem]++;
    }
}

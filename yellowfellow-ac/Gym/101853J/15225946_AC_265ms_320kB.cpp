#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int n;
        cin>>n;
        int ar[10005];
        for (int i=0;i<10005;i++){
            ar[i]=0;
        }
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            ar[a]++;
        }
        int ans=0;
        for (int i=0;i<10004;i++){
            ans=max(ans,ar[i]+ar[i+1]);
        }
        printf ("%d\n",ans);
    }
}
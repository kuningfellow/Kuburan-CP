#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n,m,k;
    cin>>n>>m>>k;
    long long int l=0;
    long long int r=n*m;
    long long int mid,ans;
    long long int tem;
    while (l<=r){
        mid=(l+r)/2;
        tem=0;
        for (int i=1;i<=min(mid-1,n);i++){
            tem+=min((mid-1)/i,m);
        }
        if (tem<k){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    printf ("%lld\n",ans);
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    n--;
    long long int l=1,r=n,mid,ans,h=(n*(n+1))/4,res;
    if ((n*(n+1)/2)%2==1)h++;
    while (l<=r){
        mid=(l+r)/2;
        res=(mid*(2*n-(mid-1)))/2;
        if (res>=h){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf ("%lld\n",ans);
}

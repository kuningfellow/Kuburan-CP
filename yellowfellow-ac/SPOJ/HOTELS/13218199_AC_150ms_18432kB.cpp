#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    long long int ar[n];
    for (int i=0;i<n;i++){
        cin>>ar[i];
    }
    long long int best=0;
    long long int sum=0;
    int lef=0;
    for (int i=0;i<n;i++){
        if (sum+ar[i]<=m){
            if (sum==0)lef=i;
            sum+=ar[i];
            best=max(best,sum);
        }
        else{
            while (lef<i&&sum+ar[i]>m){
                sum-=ar[lef++];
            }
            sum+=ar[i];
            best=max(best,sum);
        }
    }
    printf ("%lld\n",best);
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long int n;
    cin>>n;
    long long int cost=n/2;
    long long int div=0;
    for (int i=1;i<50;i++){
        div=(1ll<<i);
        div*=2;
        int add=0;
        long long int rem=n-(n/div)*div;
        if (rem>div/2){
            add=1;
        }
        cost+=(1ll<<i)*(n/div+add);
    }
    printf ("%lld\n",cost);
}
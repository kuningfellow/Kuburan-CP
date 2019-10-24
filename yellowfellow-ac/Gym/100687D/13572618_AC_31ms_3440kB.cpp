#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long int n,m,k;
    cin>>n>>m>>k;
    long long int sum=n+m;
    if (sum>k*3){
        printf ("-1\n");
        return 0;
    }
    long long int coun=0;
    long long int tmp=(n/3+(n%3>0));
    coun+=n;
    k-=tmp;
    long long int c=0;
    if (n%3>0){
        c=3-n%3;
    }
    coun+=min(m,(k*3+c-m)/2);
    printf ("%lld\n",sum-coun);
}
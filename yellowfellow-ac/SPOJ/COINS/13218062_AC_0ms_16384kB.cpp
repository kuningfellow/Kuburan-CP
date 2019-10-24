#include <bits/stdc++.h>
using namespace std;
map<int,long long int>memo;
long long int func(int x){
    if (memo[x]!=0)return memo[x];
    if (x/2+x/3+x/4>x){
        return memo[x]=func(x/2)+func(x/3)+func(x/4);
    }
    return memo[x]=x;
}
int main(){
    long long int n;
    while (scanf("%lld",&n)!=EOF){
        memo.clear();
        printf ("%lld\n",func(n));
    }
}

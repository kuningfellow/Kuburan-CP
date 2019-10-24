//UVA 11984 A Change in Thermal Unit
#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc,kas=1;
    cin>>tc;
    while (tc--){
        double t,d;
        cin>>t>>d;
        t+=d*5/9;
        printf ("Case %d: %.2f\n",kas++,t);
    }
}
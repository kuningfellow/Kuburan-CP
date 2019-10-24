//UVA 11677 Alarm Clock
#include <bits/stdc++.h>
using namespace std;
int main(){
    while (1<2){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if (a+b+c+d==0)break;
        int A=a*60+b;
        int B=c*60+d;
        int mod=24*60;
        printf ("%d\n",((B-A)%mod+mod)%mod);
    }
}
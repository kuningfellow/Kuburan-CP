//UVA 12136 Schedule of a Married Man
#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc,kas=1;
    cin>>tc;
    while (tc--){
        int h1,m1,h2,m2;
        scanf("%d:%d%d:%d",&h1,&m1,&h2,&m2);
        int t1s=h1*60+m1;
        int t1e=h2*60+m2;
        scanf("%d:%d%d:%d",&h1,&m1,&h2,&m2);
        int t2s=h1*60+m1;
        int t2e=h2*60+m2;
        printf ("Case %d: ",kas++);
        if ((t2s<=t1e&&t2s>=t1s)||(t2e>=t1s&&t2e<=t1e)||(t1s<=t2e&&t1s>=t2s)||(t1e>=t2s&&t1e<=t2e)){
            printf ("Mrs Meeting\n");
        }
        else
            printf ("Hits Meeting\n");
    }
}
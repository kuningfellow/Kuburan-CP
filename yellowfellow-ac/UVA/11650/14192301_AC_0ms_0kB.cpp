//UVA 11650 Mirror Clock
#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int h,m;
        scanf("%d:%d",&h,&m);
        int t=h*60+m;
        int day=60*12;
        t=day-t;
        t=(t%day+day)%day;
        h=0;
        while (t>=60){
            t-=60;
            h++;
        }
        if (h==0)
            h=12;
        printf ("%02d:%02d\n",h,t);
    }
}
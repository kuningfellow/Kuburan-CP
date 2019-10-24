//UVA 10683 The decadary watch
#include <bits/stdc++.h>
using namespace std;
int main(){
    char rem[500];
    while (scanf("%s",rem)!=EOF){
        double tot=0;
        int h=(rem[0]-'0')*10+rem[1]-'0';
        int m=(rem[2]-'0')*10+rem[3]-'0';
        int s=(rem[4]-'0')*10+rem[5]-'0';
        int ms=(rem[6]-'0')*10+rem[7]-'0';
        tot=h*360000+m*6000+s*100+ms;
        double day=24*60*60*100;
        double day2=10*100*100*100;
        tot=tot*day2/day;
        h=0;
        m=0;
        s=0;
        ms=0;
        while (tot>=1000000){
            h++;
            tot-=1000000;
        }
        while (tot>=10000){
            m++;
            tot-=10000;
        }
        while (tot>=100){
            s++;
            tot-=100;
        }
        ms=tot;
        printf ("%01d%02d%02d%02d\n",h,m,s,ms);
    }
}
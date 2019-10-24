//UVA 10339 Watching Watches
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int a,b;
    while (scanf("%lld%lld",&a,&b)!=EOF){
        double base=43200;
        double r1=base/(base-(double)a/2);
        double r2=base/(base-(double)b/2);
        if (r1>r2){
            double temp=r1;
            r1=r2;
            r2=temp;
        }
        double del=r2-r1;
        double now=r1;
        while (now/del>1-1e-9){
            now-=r2;
            while (now<0){
                now+=r1;
            }
        }
        double t=base*now/del+1e-2;
        int h=0,m=0;
        while (t>=3600){
            h++;
            t-=3600;
        }
        while (t>=60){
            m++;
            t-=60;
        }
        if (t>=30){
            m++;
        }
        if (m==60){
            m=0;
            h++;
        }
        if (h==0)h=12;
        printf ("%lld %lld %02d:%02d\n",a,b,h,m);
    }
}
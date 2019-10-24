//UVA 11309 Counting Chaos
#include <bits/stdc++.h>
using namespace std;
bool pal(int h, int m){
    char rem[3]="00";
    int rel=0;
    char ram[3]="00";
    int ral=0;
    while (h>0){
        rem[rel++]=h%10+'0';
        h/=10;
    }
    while (m>0){
        ram[ral++]=m%10+'0';
        m/=10;
    }
    if (rel>0){
        ral=2;
    }
    int l=rel+ral;
    char comp[l];
    for (int i=0;i<ral;i++){
        comp[i]=ram[i];
    }
    for (int i=ral;i<l;i++){
        comp[i]=rem[i-ral];
    }
    int pl=0;
    while (pl<l){
        if (comp[pl]!=comp[l-1-pl])break;
        pl++;
    }
    if (pl==l)return 0;
    return 1;
}
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int h,m;
        scanf("%d:%d",&h,&m);
        int fir=1;
        while (fir==1||pal(h,m)){
            fir=0;
            m++;
            h+=m/60;
            m%=60;
            h%=24;
        }
        printf("%02d:%02d\n",h,m);
    }
}
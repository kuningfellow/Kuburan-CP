#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e,f;
    while (scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)!=EOF){
        double l=0,r=1,mid,ans=-1;
        for (int i=0;i<100;i++){
            mid=(l+r)/2;
            if (a*exp(-mid)+b*sin(mid)+c*cos(mid)+d*tan(mid)+e*mid*mid+f>0){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        double res=a*exp(-mid)+b*sin(mid)+c*cos(mid)+d*tan(mid)+e*mid*mid+f;
        res=max(res,-res);
        if (res<1e-5)
            printf ("%.4f\n",mid);
        else printf ("No solution\n");
    }
}

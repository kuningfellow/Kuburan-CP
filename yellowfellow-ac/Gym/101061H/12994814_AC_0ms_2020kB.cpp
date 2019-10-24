#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int l,r,v1,v2,t;
        cin>>l>>r>>v1>>v2>>t;
        if (v1==v2){
            printf ("%.3f %.3f\n",0.0,(double)2*PI*r*v1*t);
        }
        else{
            int dir=1;
            if (v1>v2){
                dir=v1;
                v1=v2;
                v2=dir;
                dir=-1;
            }
            double s=2*PI*r*v1*t;
            double S=2*PI*r*v2*t;
            double d=(double)s*l/(S-s);
            double deg=(double)S/(d+l);
            double shift=-(d+(double)l/2);
            double com=d+(double)l/2;
            printf ("%.3f %.3f\n",dir*shift+dir*com*(cos(deg)),com*(sin(deg)));
        }
    }
}

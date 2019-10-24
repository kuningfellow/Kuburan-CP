#include <bits/stdc++.h>
using namespace std;
int main(){
    while (1<2){
        int a,b;
        cin>>a>>b;
        if (a==0&&b==0)break;
        double l=0,r=a,mid,ans;
        for (int i=0;i<100;i++){
            mid=(l+r)/2;
            if (b*6>2*acos(0)*(a*a*a-mid*mid*mid)){
                r=mid;
            }
            else{
                l=mid;
            }
        }
        printf ("%.3f\n",mid);
    }
}

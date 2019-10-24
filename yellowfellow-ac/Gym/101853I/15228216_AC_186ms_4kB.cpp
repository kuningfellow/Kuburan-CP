#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int a,b;
        double c;
        scanf("%d%d",&a,&b);
        scanf("%lf",&c);
        printf ("%.6f\n",c*c/2);
    }
}
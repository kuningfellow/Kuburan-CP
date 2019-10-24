#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    double x,V;
    cin>>x>>V;
    double shift=0;
    double l,r,v;
    for (int i=0;i<n;i++){
        cin>>l>>r>>v;
        shift+=(r-l)*v;
    }
    double deg=asin(shift/(V*x));
    if ( shift/(V*x)>1 || shift/(V*x) < -1 ){
        printf ("Too hard\n");
    }
    else printf ("%.3lf\n",x/(V*cos(deg)));
}

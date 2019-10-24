//UVA 11945 Financial Management
#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc,kas=1;
    cin>>tc;
    while (tc--){
        double ar[12];
        double sum=0;
        for (int i=0;i<12;i++){
            cin>>ar[i];
            sum+=ar[i];
        }
        sum/=12;
        printf ("%d $",kas++);
        long long int temp=sum;
        double tail=sum-temp;
        long long int round=tail*10000;
        if (round%100>=50&&round%100!=99){
            sum+=0.01;
        }
        temp=sum;
        tail=sum-temp;
        stack<int>st;
        while (temp>0){
            st.push(temp%1000);
            temp/=1000;
        }
        int fir=1;
        while (!st.empty()){
            if (fir==1){
                printf ("%lld",st.top());
            }
            else{
                printf ("%03lld",st.top());
            }
            fir=0;
            st.pop();
            if (!st.empty()){
                printf (",");
            }
        }
        temp=(tail+1e-4)*1000;
        temp/=10;
        printf (".%02lld\n",temp%100);
    }
}
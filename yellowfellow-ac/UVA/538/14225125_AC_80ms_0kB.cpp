//UVA 538 Balancing Bank Accounts
#include <bits/stdc++.h>
using namespace std;
struct dat{
    string str;
    int monet;
};
map<string,int>cor;
int main(){
    int kas=1;
    while (1<2){
        int n,t;
        cin>>n>>t;
        if (n==0&&t==0)break;
        dat ar[n];
        cor.clear();
        for (int i=0;i<n;i++){
            cin>>ar[i].str;
            cor[ar[i].str]=i;
            ar[i].monet=0;
        }
        string rem,ram;
        int tr;
        for (int i=0;i<t;i++){
            cin>>rem>>ram>>tr;
            ar[cor[ram]].monet+=tr;
            ar[cor[rem]].monet-=tr;
        }
        int prev=-1;
        printf ("Case #%d\n",kas++);
        for (int i=0;i<n;i++){
            if (ar[i].monet>0){
                if (prev!=-1){
                    ar[i].monet+=ar[prev].monet;
                    cout<<ar[prev].str<<" "<<ar[i].str<<" "<<ar[prev].monet<<endl;
                    ar[prev].monet=0;
                }
                prev=i;
            }
        }
        for (int i=0;i<n;i++){
            if (ar[i].monet<0){
                ar[i].monet+=ar[prev].monet;
                cout<<ar[prev].str<<" "<<ar[i].str<<" "<<ar[prev].monet<<endl;
                ar[prev].monet=0;
                prev=i;
            }
        }
        printf ("\n");
    }
}
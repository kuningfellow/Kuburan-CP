#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int n;
        cin>>n;
        int ar[n];
        for (int i=0;i<n;i++)
            ar[i]=-1;
        int x=1;
        int foun=1;
        while (foun){
            foun=0;
            for (int i=0;i<n;i++){
                if (ar[i]==-1||((int)sqrt(ar[i]+x))*((int)sqrt(ar[i]+x))==ar[i]+x){
                    foun=1;
                    ar[i]=x++;
                    break;
                }
            }
        }
        printf ("%d\n",x-1);
    }
}

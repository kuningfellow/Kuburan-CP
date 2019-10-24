#include <bits/stdc++.h>
using namespace std;
int n;
int ar[15];
vector<int>lis;
void lotto(int x,int p){
    if (x==6){
        for (int i=0;i<lis.size();i++){
            printf ("%d",ar[lis[i]]);
            if (i<lis.size()-1)printf (" ");
        }
        printf ("\n");
        return;
    }
    for (int i=p+1;i<n;i++){
        lis.push_back(i);
        lotto(x+1,i);
        lis.pop_back();
    }
    return;
}
int main(){
    int fir=1;
    while (1<2){
        cin>>n;
        if (n==0)break;
        if (fir==0)printf ("\n");
        fir=0;
        for (int i=0;i<n;i++){
            cin>>ar[i];
        }
        lotto(0,-1);
    }
}

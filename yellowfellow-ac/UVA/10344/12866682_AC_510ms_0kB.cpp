#include <bits/stdc++.h>
using namespace std;
int ar[5];
int serc(int x, int mask){
    if (mask==(1<<5)-1&&x==23){
        return 1;
    }
    if (mask==(1<<5)-1&&x!=23){
        return 0;
    }
    int ret=0;
    for (int i=0;i<5;i++){
        if ((mask&(1<<i))==0){
            ret=max(ret,serc(x+ar[i],mask|(1<<i)));
            ret=max(ret,serc(x*ar[i],mask|(1<<i)));
            ret=max(ret,serc(x-ar[i],mask|(1<<i)));
        }
    }
    return ret;
}
int main(){
    while (1<2){
        int br=1;
        for (int i=0;i<5;i++){
            cin>>ar[i];
            if (ar[i]!=0)br=0;
        }
        if (br)break;
        int ret=0;
        for (int i=0;i<5;i++){
            ret=max(ret,serc(ar[i],(1<<i)));
        }
        if (ret){
            printf ("Possible\n");
        }
        else printf ("Impossible\n");
    }
}

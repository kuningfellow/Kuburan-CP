#include <bits/stdc++.h>
using namespace std;
int ar[8];
int serc(int x, int p){
    if (x==8)return 0;
    int temp=p;
    int br[8];
    int lev=0;
    int pow=1;
    while (temp>0){
        br[lev++]=temp%10;
        temp/=10;
        pow*=10;
    }
    int val;
    int ret=(1<<30);
    for (int i=0;i<8;i++){
        val=1;
        for (int j=0;j<lev;j++){
            if (i+1==br[j]||max(i+1-br[j],br[j]-i-1)==max(x-j,j-x)){
                val=0;
                break;
            }
        }
        if (val==1){
            int et=0;
            if (i+1!=ar[x])et=1;
            ret=min(ret,et+serc(x+1,p+(i+1)*pow));
        }
    }
    return ret;
}
int main(){
    int kas=1;
    while (scanf("%d%d%d%d%d%d%d%d",&ar[0],&ar[1],&ar[2],&ar[3],&ar[4],&ar[5],&ar[6],&ar[7])!=EOF){
        printf ("Case %d: %d\n",kas++,serc(0,0));
    }
}

#include <bits/stdc++.h>
using namespace std;
vector<int>sols[8];
vector<int>tem;
void serc(int x, int p){
    if (x==8){
        for (int i=0;i<8;i++){
            sols[i].push_back(tem[i]);
        }
        return;
    }
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
            tem.push_back(i+1);
            serc(x+1,p+(i+1)*pow);
            tem.pop_back();
        }
    }
    return;
}
int main(){
    serc(0,0);
    int tc;
    cin>>tc;
    while (tc--){
        int ar[8][8];
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                cin>>ar[i][j];
            }
        }
        int maxi=0;
        int temp;
        for (int i=0;i<sols[0].size();i++){
            temp=0;
            for (int j=0;j<8;j++){
                temp+=ar[sols[j][i]-1][j];
            }
            maxi=max(temp,maxi);
        }
        printf ("%5d\n",maxi);
    }
}

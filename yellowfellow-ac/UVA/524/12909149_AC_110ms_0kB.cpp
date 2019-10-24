#include <bits/stdc++.h>
using namespace std;
bool isprime[35];
void sive(){
    for (int i=2;i<35;i++){
        for (int j=i*2;j<35;j+=i){
            isprime[j]=1;
        }
    }
}
vector<int>lis;
int n;
int serc(int x, int mask){
    if (mask==(1<<n)-1){
        if (isprime[1+x]==0){
            printf ("1");
            for (int i=0;i<lis.size();i++){
                printf (" %d",lis[i]);
            }
            printf ("\n");
            return 1;
        }
        return 0;
    }
    int ret=0;
    for (int i=0;i<n;i++){
        if ((mask&(1<<i))==0&&isprime[x+i+1]==0){
            lis.push_back(i+1);
            ret=max(ret,serc(i+1,mask|(1<<i)));
            lis.pop_back();
        }
    }
    return ret;
}
int main(){
    sive();
    int kas=1;
    while (scanf("%d",&n)!=EOF){
        if (n<1||n>16)break;
        if (kas!=1)printf ("\n");
        printf ("Case %d:\n",kas++);
        serc(1,1);
        lis.clear();
    }
}
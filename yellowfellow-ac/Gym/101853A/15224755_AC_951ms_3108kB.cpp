#include<bits/stdc++.h>
using namespace std;
map<int,int>cnt;
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        cnt.clear();
        int n,q;
        scanf("%d%d",&n,&q);
        int ar[n];
        int uniq=0;
        for (int i=0;i<n;i++){
            scanf("%d",&ar[i]);
            if (cnt[ar[i]]==0&&ar[i]!=0){
                uniq++;
            }
            cnt[ar[i]]++;
        }
        for (int i=0;i<q;i++){
            int a;
            scanf("%d",&a);
            if (a==2){
                printf ("%d\n",uniq);
            }
            else{
                int b,c;
                scanf("%d%d",&b,&c);
                cnt[ar[b-1]]--;
                if (cnt[ar[b-1]]==0&&ar[b-1]!=0){
                    uniq--;
                }
                ar[b-1]=c;
                if (cnt[c]==0&&c!=0){
                    uniq++;
                }
                cnt[c]++;
            }
        }
    }
}
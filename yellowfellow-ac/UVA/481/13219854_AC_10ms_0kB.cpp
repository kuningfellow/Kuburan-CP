#include <bits/stdc++.h>
using namespace std;
int ar[1000005];
int lis[1000005];
int bac[1000005];
int main(){
    ar[0]=-(1<<30);
    bac[0]=0;
    int siz=1;
    int maxi=0;
    while (scanf("%d",&ar[siz++])!=EOF);
    siz--;
    for (int i=1;i<siz;i++){
        int l=0,r=maxi,mid,ans=0;
        while (l<=r){
            mid=(l+r)/2;
            if (ar[lis[mid]]<ar[i]){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        bac[i]=lis[ans];
        lis[ans+1]=i;
        maxi=max(maxi,ans+1);
    }
    printf ("%d\n-\n",maxi);
    int trace=lis[maxi];
    vector<int>print;
    while (trace!=0){
        print.push_back(trace);
        trace=bac[trace];
    }
    for (int i=print.size()-1;i>=0;i--){
        printf ("%d\n",ar[print[i]]);
    }
}

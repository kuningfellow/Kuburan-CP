//resubmit buat tugas
#include <bits/stdc++.h>
using namespace std;
int ar[500005];
int temp[500005];
long long int coun;
void merg(int l, int r){
    int pl=l;
    int mid=(l+r)/2;
    int pr=mid+1;
    for (int i=l;i<=r;i++){
        if (pl==mid+1){
            coun+=(long long int)pr-i;
            temp[i]=ar[pr++];
        }
        else if (pr==r+1){
            temp[i]=ar[pl++];
        }
        else if (ar[pl]>ar[pr]){
            coun+=(long long int)pr-i;
            temp[i]=ar[pr++];
        }
        else{
            temp[i]=ar[pl++];
        }
    }
    for (int i=l;i<=r;i++){
        ar[i]=temp[i];
    }
}
void hanoi(int l, int r){
    if (l>=r)return;
    int mid=(l+r)/2;
    hanoi(l,mid);
    hanoi(mid+1,r);
    merg(l,r);
}
int main(){
    while (1<2){
        int n;
        cin>>n;
        if (n==0)break;
        for (int i=0;i<n;i++){
            scanf("%d",&ar[i]);
        }
        coun=0;
        hanoi(0,n-1);
        printf ("%lld\n",coun);
    }
}
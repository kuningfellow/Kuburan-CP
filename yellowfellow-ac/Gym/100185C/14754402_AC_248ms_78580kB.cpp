#include<bits/stdc++.h>
using namespace std;
int cnt[2005][10005];
int reg[10005];
int ar[2005];
int main(){
	int l1,l2,n;
	cin>>l1>>l2>>n;
	for (int i=0;i<n;i++){
		scanf("%d",&ar[i]);
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i==j||ar[i]+ar[j]>10000)continue;
			cnt[i][ar[i]+ar[j]]+=2;
			reg[ar[i]+ar[j]]++;
		}
	}
	int ans=-1;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i==j||ar[i]+ar[j]>l1)continue;
			for (int k=l2;k>=0;k--){
				if (reg[k]-cnt[i][k]-cnt[j][k]+(ar[i]+ar[j]==k)*2>0){
					ans=max(ans,k+ar[i]+ar[j]);
					break;
				}
			}
		}
	}
	if (ans==-1)printf ("Impossible\n");
	else printf ("%d\n",ans);
}
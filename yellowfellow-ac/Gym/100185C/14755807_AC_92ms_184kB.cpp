#include<bits/stdc++.h>
using namespace std;
int cnt[10005];
int reg[10005];
int ar[2005];
int lis[10005][2];
int main(){
	int l1,l2,n;
	cin>>l1>>l2>>n;
	for (int i=0;i<n;i++){
		scanf("%d",&ar[i]);
		cnt[ar[i]]++;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i==j||ar[i]+ar[j]>10000)continue;
			reg[ar[i]+ar[j]]++;
		}
	}
	for (int i=0;i<=l1;i++){
		lis[i][0]=lis[i][1]=-1;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i==j||ar[i]+ar[j]>l1||lis[ar[i]+ar[j]][0]!=-1)continue;
			lis[ar[i]+ar[j]][0]=i;
			lis[ar[i]+ar[j]][1]=j;
		}
	}
	int ans=-1;
	for (int i=l1;i>=0;i--){
		if (lis[i][0]==-1)continue;
		if (i+l2<ans)break;
		for (int k=l2;k>=0;k--){
			int red=0;
			if (k-ar[lis[i][0]]>=0)
				red+=2*(cnt[k-ar[lis[i][0]]]-(k-ar[lis[i][0]]==ar[lis[i][0]]));
			if (k-ar[lis[i][1]]>=0)
				red+=2*(cnt[k-ar[lis[i][1]]]-(k-ar[lis[i][1]]==ar[lis[i][1]]));
			if (reg[k]-red+(i==k)*2>0){
				ans=max(ans,k+i);
				break;
			}
		}
	}
	if (ans==-1)printf ("Impossible\n");
	else printf ("%d\n",ans);
}
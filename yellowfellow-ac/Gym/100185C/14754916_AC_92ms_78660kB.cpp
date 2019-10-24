#include<bits/stdc++.h>
using namespace std;
int cnt[2005][10005];
int reg[10005];
int ar[2005];
int lis[10005][2];
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
		for (int k=l2;k>=0;k--){
			// if (i+k<ans)break;
			if (reg[k]-cnt[lis[i][0]][k]-cnt[lis[i][1]][k]+(i==k)*2>0){
				ans=max(ans,k+i);
				break;
			}
		}
		// if (i+l2<ans)break;
	}
	if (ans==-1)printf ("Impossible\n");
	else printf ("%d\n",ans);
}
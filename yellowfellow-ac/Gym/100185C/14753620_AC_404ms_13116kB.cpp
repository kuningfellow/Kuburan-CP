#include<bits/stdc++.h>
using namespace std;
int vis1[10005][2];
vector<pair<int,int> >vis2[10005];
int main(){
	int l1,l2,n;
	cin>>l1>>l2>>n;
	int ar[n];
	for (int i=0;i<=l1;i++){
		vis1[i][0]=vis1[i][1]=-1;
	}
	for (int i=0;i<n;i++){
		scanf("%d",&ar[i]);
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i==j)continue;
			if (ar[i]+ar[j]>l1)continue;
			if (vis1[ar[i]+ar[j]][0]==-1){
				vis1[ar[i]+ar[j]][0]=i;
				vis1[ar[i]+ar[j]][1]=j;
			}
		}
	}
	for (int i=n-1;i>=0;i--){
		for (int j=i;j>=0;j--){
			if (i==j)continue;
			if (ar[i]+ar[j]>l2)continue;
			vis2[ar[i]+ar[j]].push_back(pair<int,int>(i,j));
		}
	}
	int mark[n];
	for (int i=0;i<n;i++){
		mark[i]=0;
	}
	int ans=-1;
	for (int i=l1;i>=0;i--){
		if (vis1[i][0]==-1)continue;
		for (int j=l2;j>=0;j--){
			if (i+j<ans)continue;
			if (vis2[j].size()!=0){
				int val=1;
				mark[vis1[i][0]]++;
				mark[vis1[i][1]]++;
				for (int k=0;k<vis2[j].size();k++){
					val=1;
					if (mark[vis2[j][k].first]>0){
						val=0;
						int l=0;
						int r=min(n-1,(int)vis2[j].size()-k-1);
						int mid;
						int shift=1;
						while (l<=r){
							mid=(l+r)/2;
							if (vis2[j][k+mid].first!=vis2[j][k].first){
								shift=mid;
								r=mid-1;
							}
							else{
								l=mid+1;
							}
						}
						k=k-1+shift;
						continue;
					}
					if (mark[vis2[j][k].second]>0){
						val=0;
					}
					if (val==1){
						ans=max(ans,i+j);
						break;
					}
				}
				mark[vis1[i][0]]=0;
				mark[vis1[i][1]]=0;
				if (val==1)break;
			}
		}
	}
	if (ans==-1)printf ("Impossible\n");
	else printf ("%d\n",ans);
}
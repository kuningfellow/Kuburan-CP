#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		int L,n;
		cin>>L>>n;
		int l=0,r=L,mid,ans,val,er,ver,tmp;
		int ar[n];
		for (int i=0;i<n;i++){
			scanf("%d",&ar[i]);
		}
		while (l<=r){
			mid=(l+r)/2;
			val=1;
			er=0;
			for (int i=0;i<n;i++){
				tmp=min(L-ar[i],ar[i]);
				er=max(er,tmp);
				if (max(ar[i],L-ar[i])>mid){
					val=0;
					break;
				}
			}
			if (val==1){
				ans=mid;
				ver=er;
				r=mid-1;
			}
			else l=mid+1;
		}
		printf ("%d %d\n",ver,ans);
	}
}
#include <bits/stdc++.h>
using namespace std;
int lis[15];
int main(){
	int maxi=0;
	int n,a;
	lis[0]=-1;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a;
		int l=0,r=maxi,mid,ans;
		while (l<=r){
			mid=(l+r)/2;
			if (lis[mid]<a){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		maxi=max(maxi,ans+1);
		lis[ans+1]=a;
	}
	printf ("%d\n",maxi);
}
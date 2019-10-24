#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int ar[n];
	int same=-1;
	int val=1;
	for (int i=0;i<n;i++){
		scanf("%d",&ar[i]);
		if (i==k-1){
			same=ar[i];
		}
		if (i>=k){
			if (same!=ar[i]){
				val=0;
			}
		}
	}
	if (val==0){
		printf ("-1\n");
		return 0;
	}
	int ans=-1;
	for (int i=0;i<k;i++){
		if (ar[i]!=same){
			ans=i;
		}
	}
	printf ("%d\n",ans+1);
}
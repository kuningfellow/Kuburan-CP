#include <bits/stdc++.h>
using namespace std;
long long int calc(long long int a, long long int k){
	long long int ret=0;
	while (a>0){
		ret+=a;
		a/=k;
	}
	return ret;
}
int main(){
	long long int n,k;
	cin>>n>>k;
	long long int l=1,r=1000000000,mid,ans;
	while (l<=r){
		mid=(l+r)/2;
		if (calc(mid,k)>=n){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	printf ("%lld\n",ans);
}
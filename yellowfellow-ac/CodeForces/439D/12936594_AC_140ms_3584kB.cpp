#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int n,m;
long long int ar[100005];
long long int br[100005];
long long int func(long long int x){
	long long int ret=0;
	for (int i=0;i<n;i++){
		ret+=max(0ll,x-ar[i]);
	}
	for (int i=0;i<m;i++){
		ret+=max(0ll,br[i]-x);
	}
	return ret;
}
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++){
		scanf("%lld",&ar[i]);
	}
	for (int i=0;i<m;i++){
		scanf("%lld",&br[i]);
	}
	long long int l=0,r=1000000000,mid1,mid2,sl,sr;
	long long t1;
	long long t2;
	while (l<=r){
		sl=l;
		sr=r;
		mid1=(2*l+r)/3;
		mid2=(l+2*r)/3;
		t1=func(mid1);
		t2=func(mid2);
		if (t1<=t2){
			r=mid2-1;
		}
		else{
			l=mid1+1;
		}
	}
	long long int ans=func(sr);
	for (long long int i=sl;i<sr;i++){
		ans=min(ans,func(i));
	}
	printf ("%lld\n",ans);
}
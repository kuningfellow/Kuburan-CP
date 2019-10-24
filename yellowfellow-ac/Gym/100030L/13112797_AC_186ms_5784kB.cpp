#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	long long int ar[n+1];
	long long int br[n+1];
	br[0]=0;
	for (int i=0;i<n;i++){
		scanf("%lld%lld",&ar[i],&br[i+1]);
	}
	ar[n]=(1<<30);
	sort(ar,ar+n+1);
	sort(br,br+n+1);
	long long int prefsum[n+1];
	prefsum[0]=0;
	for (int i=1;i<=n;i++){
		prefsum[i]=prefsum[i-1]+ar[n-i];
	}
	int l,r,mid,ans;
	long long int maxi=0;
	int jawb;
	for (int i=n;i>0;i--){
		l=0;
		r=n;
		while (l<=r){
			mid=(l+r)/2;
			if (ar[mid]<=br[i]){
				l=mid+1;
			}
			else{
				ans=mid;
				r=mid-1;
			}
		}
		int pref=n-ans;
		long long int res=prefsum[pref];
		l=0;
		r=n;
		ans=-1;
		while (l<=r){
			mid=(l+r)/2;
			if (br[mid]<br[i]){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		int notpaying = ans;
		res+=(n-pref-notpaying)*br[i];
		if (res>=maxi){
			maxi=res;
			jawb=br[i];
		}
	}
	printf ("%d %lld\n",jawb,maxi);
}
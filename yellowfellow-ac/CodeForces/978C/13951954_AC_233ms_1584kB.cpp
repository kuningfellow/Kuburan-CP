#include <bits/stdc++.h>

long long int ar[200005];
int n;
namespace function{
	inline int search(long long int v){
		int l=0;
		int r=n-1;
		int mid,ans;
		while (l<=r){
			mid=(l+r)/2;
			if (ar[mid]<v){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		return ans;
	}
	inline void prefix_sum(){
		ar[0]=0;
		long long int carry=0;
		for (int i=1;i<n;i++){
			ar[i]+=ar[i-1];
		}
	}
	inline void calculate(int idx, long long int v){
		v-=ar[idx];
		printf ("%d %lld\n",idx+1,v);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int m;
	scanf("%d%d",&n,&m);
	n++;
	for (int i=1;i<n;i++){
		scanf("%lld",&ar[i]);
	}
	function::prefix_sum();
	for (int i=0;i<m;i++){
		long long int v;
		scanf("%lld",&v);
		int idx=function::search(v);
		function::calculate(idx,v);
	}
}
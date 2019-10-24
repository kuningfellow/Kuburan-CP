#include <bits/stdc++.h>

namespace function{
	int search(long long int ar[], int n, long long int v){
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
	void prefix_sum(long long int ar[], int n){
		ar[0]=0;
		long long int carry=0;
		for (int i=1;i<n;i++){
			ar[i]+=ar[i-1];
		}
	}
	void calculate(long long int ar[], int idx, long long int v){
		v-=ar[idx];
		printf ("%d %lld\n",idx+1,v);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int n,m;
	std::cin>>n>>m;
	n++;
	long long int ar[n];
	for (int i=1;i<n;i++){
		std::cin>>ar[i];
	}
	function::prefix_sum(ar,n);
	for (int i=0;i<m;i++){
		long long int v;
		std::cin>>v;
		int idx=function::search(ar,n,v);
		function::calculate(ar,idx,v);
	}
}
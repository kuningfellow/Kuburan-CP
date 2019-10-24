#include <bits/stdc++.h>

namespace i_am_so_sexy{
	void solve(long long int ar[], int n, long long int w){
		long long int min=0,max=0,carry=0;
		for (int i=0;i<n;i++){
			carry+=ar[i];
			if (min>carry)min=carry;
			if (max<carry)max=carry;
		}
		long long int range=max-min;
		if (range>w){
			printf ("0\n");
		}
		else{
			printf ("%lld\n",w-range+1);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int n;
	long long int w;
	std::cin>>n>>w;
	long long int ar[n];
	for (int i=0;i<n;i++){
		std::cin>>ar[i];
	}
	i_am_so_sexy::solve(ar,n,w);
}
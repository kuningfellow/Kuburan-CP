#include <bits/stdc++.h>

namespace sexy_mi_mi{
	void solve(int ar[], int n){
		int take[1005];
		int cnt=0;
		for (int i=0;i<1005;i++){
			take[i]=0;
		}
		for (int i=n-1;i>=0;i--){
			if (take[ar[i]]==1){
				ar[i]=-1;
				cnt++;
			}
			take[ar[i]]=1;
		}
		printf ("%d\n",n-cnt);
		for (int i=0;i<n;i++){
			if (ar[i]<0)continue;
			printf ("%d",ar[i]);
			if (i<n-1)printf (" ");
		}
		printf ("\n");
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int n;
	std::cin>>n;
	int ar[n];
	for (int i=0;i<n;i++){
		std::cin>>ar[i];
	}
	sexy_mi_mi::solve(ar,n);
}
#include <bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	long long int maxi=-(1<<28);
	long long int a;
	long long int b;
	for (int i=0;i<n;i++){
		cin>>a;
		if (a<0){
			maxi=max(maxi,a);
			continue;
		}
		b=sqrt(a);
		if (b*b!=a){
			maxi=max(maxi,a);
		}
	}
	printf ("%lld\n",maxi);
}
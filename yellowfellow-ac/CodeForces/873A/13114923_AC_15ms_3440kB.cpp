#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k,x;
	cin>>n>>k>>x;
	int ar[n];
	for (int i=0;i<n;i++){
		cin>>ar[i];
	}
	sort(ar,ar+n);
	int ans=0;
	for (int i=0;i<n-k;i++){
		ans+=ar[i];
	}
	ans+=k*x;
	printf ("%d\n",ans);
}
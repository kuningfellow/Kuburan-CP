#include <bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	int ar[n*2];
	for (int i=0;i<n*2;i++){
		cin>>ar[i];
	}
	sort(ar,ar+n*2);
	if (ar[n-1]==ar[n])
		printf ("NO\n");
	else printf ("YES\n");
}
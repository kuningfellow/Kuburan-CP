#include <bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int n,h;
	cin>>n>>h;
	for (int i=1;i<n;i++){
		if (i!=1)printf (" ");
		printf ("%.12f",sqrt((double)i*h*h/n));
	}
	printf ("\n");
}
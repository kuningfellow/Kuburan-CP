#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	if (n<k){
		printf ("-1\n");
	}
	else{
		int ad=k;
		while (k*2<n){
			k+=ad;
		}
		printf ("%d\n",k);
	}
}
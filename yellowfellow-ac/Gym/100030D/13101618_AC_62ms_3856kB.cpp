#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);
	long long int n,k;
	cin>>n>>k;
	long long int e=1;
	long long int mov=0;
	n-=e;
	e*=k;
	while (n>0){
		n-=e;
		e+=e*k;
		mov++;
	}
	printf ("%lld\n",mov);
}
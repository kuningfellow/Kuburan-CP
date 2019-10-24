#include <bits/stdc++.h>
using namespace std;
int main(){
	long long int n,k;
	int q;
	cin>>n>>k>>q;
	long long int imod=1;
	long long int p=n-2;
	while (p>0){
		if (p%2==1){
			imod*=k;
			imod%=n;
		}
		k*=k;
		k%=n;
		p/=2;
	}
	for (int i=0;i<q;i++){
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		long long int pos=(b*imod)%n;
		long long int cyc=a/n;
		if (a%n>pos)cyc++;
		printf ("%lld\n",cyc);
	}
}
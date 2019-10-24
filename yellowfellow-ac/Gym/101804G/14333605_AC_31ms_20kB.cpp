#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main(){
	int n,c;
	cin>>n>>c;
	int seat=c-n*2;
	long long int perm=1;
	long long int mul=6;
	int pow=n;
	while (pow>0){
		if (pow%2==1){
			perm*=mul;
			perm%=MOD;
		}
		mul*=mul;
		mul%=MOD;
		pow/=2;
	}
	long long int A=1,B=1;
	for (long long int i=1;i<=seat;i++){
		A*=i;
		A%=MOD;
	}
	for (long long int i=1;i<=seat-n;i++){
		B*=i;
		B%=MOD;
	}
	pow=MOD-2;
	mul=B;
	B=1;
	while (pow>0){
		if (pow%2==1){
			B*=mul;
			B%=MOD;
		}
		mul*=mul;
		mul%=MOD;
		pow/=2;
	}
	long long int res=(perm*A)%MOD;
	res*=B;
	res%=MOD;
	printf ("%lld\n",res);
}
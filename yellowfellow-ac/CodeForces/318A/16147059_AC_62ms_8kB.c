#include<stdio.h>

int main(){
	long long int n, k;
	scanf("%lld%lld", &n, &k);
	printf("%lld\n", k > (n+1)/2 ? ( k - ((n+1) / 2) )*2 : k*2-1 );
}
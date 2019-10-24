#include<stdio.h>

int main(){
	
	long long int n, m, a;
	
	scanf("%lld%lld%lld", &n, &m, &a);
	
	printf("%lld\n", (n%a!=0?n/a+1:n/a)*(m%a!=0?m/a+1:m/a));
	
	return 0;
}
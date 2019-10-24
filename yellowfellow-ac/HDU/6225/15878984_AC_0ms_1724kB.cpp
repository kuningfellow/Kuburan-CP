#include<stdio.h>
using namespace std;
int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		unsigned long long int a,b,c,d;
		scanf("%llu%llu%llu%llu", &a,&b,&c,&d);
		if (a==(1llu<<62)&&a==b&&a==c&&a==d){
			printf("18446744073709551616\n", "");
		}
		else {
			printf("%llu\n", a+b+c+d);
		}
	}
}
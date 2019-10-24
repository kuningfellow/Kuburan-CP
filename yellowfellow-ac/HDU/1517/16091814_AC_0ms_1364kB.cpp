#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int n;
	while (scanf("%lld", &n) != EOF) {
		int ret = 1;
		long long int mul = 1;
		while (mul < n){
			if (ret % 2 == 1){
				mul *= 9;
			}
			else {
				mul *= 2;
			}
			ret++;
		}
		if (ret % 2 == 1){
			printf("Ollie wins.\n");
		}
		else {
			printf("Stan wins.\n");
		}
	}
}
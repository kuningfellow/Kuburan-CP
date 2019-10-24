#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int a, b;
		scanf("%d%d", &a, &b);
		a++;
		int val = 1;
		b -= a*(a-1)/2;
		if (b < 0) {
			val = 0;
		}
		if (b % (a-1) != 0) {
			val = 0;
		}
		b /= (a-1);
		if (val) printf("%d\n", a + b);
		else printf("Too drunk to count\n");
	}
}
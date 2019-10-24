#include<stdio.h>
#include<algorithm>
#include<map>

using namespace std;

int ar[105];
int gcd(int a, int b) {
	int ret = 1;
	while (ret) {
		ret = a % b;
		a = b;
		b = ret;
	}
	return a;
}

int main() {
	int n;
	scanf("%d", &n);
	int maxi = 0;
	int g = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
		if (i > 0) {
			g = gcd(g, ar[i]);
		}
		else {
			g = ar[i];
		}
		if (ar[i] > maxi) maxi = ar[i];
	}
	if ((maxi / g - n) % 2) printf("Alice\n");
	else printf("Bob\n");
	return 0;
}
#include<stdio.h>
#include<algorithm>

using namespace std;

int ar[105];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}
	sort(ar, ar + n);
	printf("%d", ar[n - 1]);
	for (int i = 1; i < n - 1; i++) {
		printf(" %d", ar[i]);
	}
	printf(" %d\n", ar[0]);
	return 0;
}
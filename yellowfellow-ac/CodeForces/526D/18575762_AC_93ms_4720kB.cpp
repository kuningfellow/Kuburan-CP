#include<stdio.h>

int kmp[1000005];
char str[1000005];

int main() {
	int A = 0, B = 0;
	int n, k;
	scanf("%d %d", &n, &k);
	scanf("%s", str);
	int j = 0;
	kmp[0] = j;
	for (int i = 1; i < n; i++) {
		while (j && str[j] != str[i]) j = kmp[j - 1];
		if (str[j] == str[i]) j++;
		kmp[i] = j;
	}
	if (k == 1) {
		for (int i = 0; i < n; i++) {
			printf("1");
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			int patlen = (i + 1) - kmp[i];
			int mul = (i + 1) / k / patlen;
			patlen = patlen * mul;
			if (i + 1 < k) {
				printf("0");
			}
			else if (patlen * k == i + 1 && kmp[i] != 0) {
				A = 0;
				B = patlen;
				printf("1");
			}
			else if (patlen * (k + 1) == i + 1 && kmp[i] != 0) {
				A = patlen;
				B = 0;
				printf("1");
			}
			else if (B > 0 && str[A] == str[i]) {
				A++;
				B--;
				printf("1");
			}
			else {
				A = 0;
				B = 0;
				printf("0");
			}
		}
	}
	printf("\n");
	return 0;
}
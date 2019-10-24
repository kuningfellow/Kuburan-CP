#include<stdio.h>

int mark[3002];

int main(){
	int n;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		mark[a] = 1;
	}
	
	for (int i = 1; i <= 3001; i++) {
		if (!mark[i]) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
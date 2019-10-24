#include<stdio.h>

int main(){
	
	int n, k, ans = 0, comp = 1;
	
	scanf("%d%d", &n, &k);
	
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (i + 1 == k) comp = a;
		if (a > 0 && a >= comp) ans++;
	}
	
	printf("%d\n", ans);
	
	return 0;
}
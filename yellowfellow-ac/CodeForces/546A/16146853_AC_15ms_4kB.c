#include<stdio.h>

int max(int a, int b){
	if (a > b) return a;
	return b;
}

int main(){
	
	int k, n, w;
	scanf("%d%d%d", &k, &n, &w);
	
	printf("%d\n", max(k * (w * (w+1) / 2) - n, 0) );
	return 0;
}
#include<stdio.h>
#include<string.h>

int main(){
	int n;
	
	scanf("%d", &n);
	while (n--) {
		char string[101];
		scanf("%s", string);
		int l = strlen(string);
		if (l > 10) printf("%c%d%c\n", string[0], l - 2, string[l - 1]);
		else printf("%s\n", string);
	}
	
	return 0;
}
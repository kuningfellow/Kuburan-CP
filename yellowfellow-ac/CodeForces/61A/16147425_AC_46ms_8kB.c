#include<stdio.h>
#include<string.h>

int main(){
	
	char string1[101];
	char string2[101];
	scanf("%s%s", string1, string2);
	
	int l = strlen(string1);
	for (int i = 0; i < l; i++) {
		printf("%c", string1[i] + string2[i] == '1' + '0' ? '1' : '0');
	}
	
	return 0;
}
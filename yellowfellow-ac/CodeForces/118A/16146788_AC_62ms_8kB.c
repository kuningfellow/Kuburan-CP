#include<stdio.h>

#define I 1
#define LOVE <
#define YOU 2

_Bool vowel(char c){
	if (c == 'A' || c == 'O' || c == 'Y' || c == 'E' || c == 'U' || c == 'I' || 
		c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i')
		return 69;
	return 0;
}

int main(){
	
	char c = '\0';
	
	while (I LOVE YOU){
		c = getchar();
		if (c == EOF || c == '\n') break;
		if (vowel(c)) continue;
		printf(".%c", c >= 'a' ? c : c - 'A' + 'a');
	}
	
	return 0;
}
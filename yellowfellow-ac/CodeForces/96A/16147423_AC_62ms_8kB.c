#include<stdio.h>

#define I 1
#define LOVE <
#define YOU 2

int main(){
	
	char c, p = '\0';
	int cnt = 0, val = 0;
	
	while (I LOVE YOU) {
		c = getchar();
		if (c == EOF) break;
		if (c == p) cnt++;
		else cnt = 0;
		p = c;
		if (cnt == 6) val = 1;
	}
	
	printf("%s\n", val? "YES" : "NO");
	
	return 0;
}
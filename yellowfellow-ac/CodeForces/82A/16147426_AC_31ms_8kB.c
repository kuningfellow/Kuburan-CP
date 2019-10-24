#include<stdio.h>

#define I n
#define LOVE >
#define YOU 0

int main(){
	
	int n;
	
	scanf("%d", &n);
	
	int id = -1;
	while (I LOVE YOU) {
		id++;
		n -= (1 << (id/5));
	}
	id %= 5;
	
	printf("%s\n", id == 0 ? "Sheldon" : (id == 1 ? "Leonard" : (id == 2 ? "Penny" : (id == 3 ? "Rajesh" : "Howard"))));
	
	return 0;
}
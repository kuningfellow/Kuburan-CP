#include<bits/stdc++.h>
using namespace std;
char str[9][69];
int ar[10];
int sta[7] = {1, 0, 4, 1, 0, 4, 1};
int sti[7] = {0, 1, 1, 4, 5, 5, 8};
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (int i = 0; i < 9; i++) {
		scanf("%s", str[i]);
	}
	for (int i = 0; i < 7; i++) {
		int prev = 2;
		int now;
		for (int j = 0; j < 10; j++) {
			if (str[sti[i]][j * 6 + sta[i]] == '.') now = -1;
			else now = 1;
			if (prev != 2 && now != prev) {
				prev = 0;
				break;
			}
			prev = now;
		}
		ar[i] = prev;
	}
	for (int i = 0; i < 7; i++) {
		if (i > 0) printf(" ");
		printf("%d", ar[i]);
	}
	printf("\n");
}
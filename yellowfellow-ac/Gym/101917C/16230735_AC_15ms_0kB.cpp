#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, s;
	scanf("%d%d", &n, &s);
	getchar();
	for (int i = 0; i < n; i++) {
		char rem[1005];
		scanf("%[^\n]", rem);
		getchar();
		int l = strlen(rem);
		for (int j = 0; j < l; j++) {
			if (rem[j] >= 'a' && rem[j] <= 'z') {
				printf("%c", (rem[j]-'a'+26-(s%26))%26+'a');
			}
			else if (rem[j] >= 'A' && rem[j] <= 'Z') {
				printf("%c", (rem[j]-'A'+26-(s%26))%26+'A');
			}
			else {
				printf ("%c", rem[j]);
			}
		}
		printf("\n");
	}
}
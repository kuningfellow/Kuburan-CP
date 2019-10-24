#include <bits/stdc++.h>
using namespace std;
int main(){
	char ram[500000];
	char rem[500000];
	while (scanf("%s",ram)!=EOF){
		scanf("%s",rem);
		int j=0;
		int yes=0;
		for (int i=0;i<strlen(rem);i++){
			if (rem[i]==ram[j]){
				j++;
			}
			if (j==strlen(ram)){
				yes=1;
				break;
			}
		}
		if (yes==0)printf ("No\n");
		else printf ("Yes\n");
	}
}
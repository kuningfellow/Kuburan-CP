#include <bits/stdc++.h>
using namespace std;
char rem[1000005];
int main(){
	scanf("%s",rem);
	int l=strlen(rem);
	int move=0;
	int add=0;
	for (int i=1;i<l;i++){
		if (rem[i]=='0'){
			move++;
			
		}
		if (rem[i]=='1'){
			add=1;
		}
	}
	for (int i=l-1;i>=0;i--){
		if (rem[i]=='1'){
			break;
		}
		move--;
	}
	l--;
	l+=add*2;
	printf ("%d\n",move+l);
}
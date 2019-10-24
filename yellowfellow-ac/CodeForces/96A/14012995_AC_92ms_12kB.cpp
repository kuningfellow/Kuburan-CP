#include <bits/stdc++.h>
using namespace std;
int main(){
	char rem[500];
	scanf("%s",rem);
	int kmp[7]={0,1,2,3,4,5,6};
	char one[8]="0000000";
	char two[8]="1111111";
	int yes=0;
	int j=0;
	int l=strlen(rem);
	for (int i=0;i<l;i++){
		while (j-1>=0&&one[j]!=rem[i]){
			j=kmp[j-1];
		}
		if (one[j]==rem[i]){
			j++;
		}
		if (j==7){
			yes=1;
			break;
		}
	}
	j=0;
	for (int i=0;i<l;i++){
		while (j-1>=0&&two[j]!=rem[i]){
			j=kmp[j-1];
		}
		if (two[j]==rem[i]){
			j++;
		}
		if (j==7){
			yes=1;
			break;
		}
	}
	if (yes)printf ("YES\n");
	else printf ("NO\n");
}
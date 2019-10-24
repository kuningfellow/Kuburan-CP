#include<bits/stdc++.h>
using namespace std;
int main(){
	int ar[4][4];
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			scanf("%d",&ar[i][j]);
		}
	}
	int die=0;
	for (int i=0;i<4;i++){
		if (ar[i][3]==1){
			for (int j=0;j<3;j++){
				if (ar[i][j]==1){
					die=1;
					break;
				}
				if (ar[(i+j+1)%4][j]==1){
					die=1;
					break;
				}
			}
		}
		if (die)break;
	}
	if (die)printf ("YES\n");
	else printf ("NO\n");
}
//UVA 141 The Spot Game
#include <bits/stdc++.h>
using namespace std;
char rem[105][55][55];
bool check(int n, int p){
	int ret=0;
	for (int k=0;k<p;k++){
		int val[4]={1,1,1,1};
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (rem[p][i][j]!=rem[k][i][j]){
					val[0]=0;
				}
				if (rem[p][i][j]!=rem[k][n-1-j][i]){
					val[1]=0;
				}
				if (rem[p][i][j]!=rem[k][j][n-1-i]){
					val[2]=0;
				}
				if (rem[p][i][j]!=rem[k][n-1-i][n-1-j]){
					val[3]=0;
				}
			}
		}
		ret=max(ret,val[0]);
		ret=max(ret,val[1]);
		ret=max(ret,val[2]);
		ret=max(ret,val[3]);
	}
	return ret;
}
int main(){
	while (1<2){
		int n;
		cin>>n;
		if (n==0)break;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				rem[0][i][j]='-';
			}
		}
		int a,b;
		char ram[50];
		int win=-1;
		for (int i=0;i<n*2;i++){
			scanf("%d%d",&a,&b);
			scanf("%s",ram);
			a--;
			b--;
			if (i!=0){
				for (int j=0;j<n;j++){
					for (int k=0;k<n;k++){
						rem[i][j][k]=rem[i-1][j][k];
					}
				}
			}
			rem[i][a][b]=ram[0];
			if (check(n,i)&&win==-1){
				win=i;
			}
		}
		if (win==-1){
			printf ("Draw\n");
		}
		else if (win%2==0){
			printf ("Player 2 wins on move %d\n",win+1);
		}
		else{
			printf ("Player 1 wins on move %d\n",win+1);
		}
	}
}
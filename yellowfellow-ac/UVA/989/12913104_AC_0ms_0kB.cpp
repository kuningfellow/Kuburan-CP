#include <bits/stdc++.h>
using namespace std;
int n;
int ar[9][9];
int tem[9][9];
int done=0;
void serc(int x, int y){
	if (x==0&&y==n*n){
		for (int i=0;i<n*n;i++){
			for (int j=0;j<n*n;j++){
				printf ("%d",tem[i][j]);
				if (j<n*n-1)printf (" ");
			}
			printf ("\n");
		}
		done=1;
		return;
	}
	if (ar[x][y]!=0){
		if (x+1==n*n){
			serc(0,y+1);
		}
		else serc(x+1,y);
		return;
	}
	int pos[10];
	for (int i=0;i<10;i++)
		pos[i]=1;
	for (int i=0;i<n*n;i++){
		pos[ar[x][i]]=0;
		pos[ar[i][y]]=0;
		pos[tem[x][i]]=0;
		pos[tem[i][y]]=0;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			pos[ar[x/n*n+i][y/n*n+j]]=0;
			pos[tem[x/n*n+i][y/n*n+j]]=0;
		}
	}
	for (int i=1;i<=n*n;i++){
		if (pos[i]==1){
			tem[x][y]=i;
			if (x+1==n*n){
				serc(0,y+1);
			}
			else serc(x+1,y);
			tem[x][y]=0;
			if (done==1)break;
		}
	}
	return;
}
int main(){
	int fir=1;
	while (scanf("%d",&n)!=EOF){
		for (int i=0;i<n*n;i++){
			for (int j=0;j<n*n;j++){
				cin>>ar[i][j];
				tem[i][j]=ar[i][j];
			}
		}
		done=0;
		if (fir==0)printf ("\n");
		fir=0;
		serc(0,0);
		if (done==0)printf ("NO SOLUTION\n");
	}
}
#include<bits/stdc++.h>
using namespace std;
int main(){
	int ar[3][3];
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			scanf("%d",&ar[i][j]);
		}
	}
	int b=(ar[1][0]+ar[2][0])-(ar[0][1]+ar[2][1]);
	int c=(ar[1][0]+ar[2][0])-(ar[0][2]+ar[1][2]);
	int start=max(0,-b);
	start=max(start,-c);
	int val=-1;
	for (int i=start;;i++){
		if (i*3+b+c==i+ar[0][1]+ar[0][2]){
			val=i;
			break;
		}
	}
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			if (i==j){
				if (i==0)printf ("%d ",val);
				else if (i==1)printf ("%d ",val+b);
				else if (i==2)printf ("%d ",val+c);
			}
			else printf ("%d ",ar[i][j]);
		}
		printf ("\n");
	}
}
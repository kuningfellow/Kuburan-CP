//UVA 232 Crossword Answers
#include <bits/stdc++.h>
using namespace std;
int main(){
	int kas=1;
	while (1<2){
		int n,m;
		cin>>n;
		if (n==0)break;
		cin>>m;
		int mark[n][m];
		char rem[n][m+1];
		int order[n*m][2];
		char str[n*m][2][50];
		for (int i=0;i<n*m;i++){
			for (int j=0;j<2;j++){
				for (int k=0;k<50;k++){
					str[i][j][k]='\0';
				}
			}
		}
		int h=0,v=0;
		for (int i=0;i<n;i++){
			scanf("%s",rem[i]);
			for (int j=0;j<m;j++){
				mark[i][j]=0;
			}
		}
		if (kas!=1)printf ("\n");
		printf ("puzzle #%d:\n",kas++);
		int cnt=0;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if (mark[i][j]!=3&&rem[i][j]!='*'){
					cnt++;
					if ((mark[i][j]&1)==0){
						order[h][0]=cnt;
						int x=i,y=j,l=0;
						while (y<m&&rem[x][y]!='*'){
							mark[x][y]|=1;
							str[h][0][l++]=rem[x][y];
							y++;
						}
						h++;
					}
					if ((mark[i][j]&2)==0){
						order[v][1]=cnt;
						int x=i,y=j,l=0;
						while (x<n&&rem[x][y]!='*'){
							mark[x][y]|=2;
							str[v][1][l++]=rem[x][y];
							x++;
						}
						v++;
					}
				}
			}
		}
		printf ("Across\n");
		for (int i=0;i<h;i++){
			printf ("%3d.%s\n",order[i][0],str[i][0]);
		}
		printf ("Down\n");
		for (int i=0;i<v;i++){
			printf ("%3d.%s\n",order[i][1],str[i][1]);
		}
	}
}
//UVA 114 Simulation Wizardry
#include <bits/stdc++.h>
using namespace std;
int main(){
	int ar[55][55][3];
	for (int i=0;i<55;i++){
		for (int j=0;j<55;j++){
			ar[i][j][0]=ar[i][j][1]=ar[i][j][2]=0;
		}
	}
	int m,n,wc,o;
	cin>>m>>n>>wc>>o;
	for (int i=0;i<o;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		ar[a][b][0]=1;
		ar[a][b][1]=d;
		ar[a][b][2]=c;
	}
	int x,y,d,t;
	int tot=0;
	while (scanf("%d%d%d%d",&x,&y,&d,&t)!=EOF){
		int temp=0;
		while (t>0){
			if (d==0)x++;
			else if (d==1)y++;
			else if (d==2)x--;
			else if (d==3)y--;
			t--;
			if (t<=0)break;
			if (ar[x][y][0]==1){
				if (t>0)temp+=ar[x][y][2];
				t-=ar[x][y][1];
				if (d==0)x--;
				else if (d==1)y--;
				else if (d==2)x++;
				else if (d==3)y++;
				d=(d+3)%4;
			}
			if (x==1||x==m||y==1||y==n){
				if (d==0)x--;
				else if (d==1)y--;
				else if (d==2)x++;
				else if (d==3)y++;
				d=(d+3)%4;
				t-=wc;
			}
		}
		tot+=temp;
		printf ("%d\n",temp);
	}
	printf ("%d\n",tot);
}
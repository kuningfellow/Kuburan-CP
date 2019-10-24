//UVA 379 Hi-Q
#include <bits/stdc++.h>
using namespace std;
int main(){
	int point[7][7]={0,0,1,2,3,0,0,
					 0,0,4,5,6,0,0,
					 7,8,9,10,11,12,13,
					 14,15,16,17,18,19,20,
					 21,22,23,24,25,26,27,
					 0,0,28,29,30,0,0,
					 0,0,31,32,33,0,0};
	int tc;
	cin>>tc;
	printf ("HI Q OUTPUT\n");
	while (tc--){
		int ma[7][7];
		for (int i=0;i<7;i++){
			for (int j=0;j<7;j++){
				ma[i][j]=-1;
			}
		}
		for (int i=2;i<5;i++){
			for (int j=0;j<7;j++){
				ma[i][j]=0;
				ma[j][i]=0;
			}
		}
		int x;
		while (1<2){
			scanf("%d",&x);
			if (x==0)break;
			if (x<=6)ma[(x-1)/3][(x-1)%3+2]=1;
			else if (x<=27)ma[(x-7)/7+2][(x-7)%7]=1;
			else if (x<=33)ma[(x-28)/3+5][(x-28)%3+2]=1;
		}
		while (1<2){
			int maxi=0;
			int bx=-1;
			int by=-1;
			int dir=-1;
			for (int i=0;i<7;i++){
				for (int j=0;j<7;j++){
					if (ma[i][j]!=1)continue;
					if (i+2<7&&ma[i+1][j]==1&&ma[i+2][j]==0){
						int temp=point[i+2][j]*100+point[i][j];
						if (temp>maxi){
							maxi=temp;
							bx=i;
							by=j;
							dir=0;
						}
					}
					if (i-2>=0&&ma[i-1][j]==1&&ma[i-2][j]==0){
						int temp=point[i-2][j]*100+point[i][j];
						if (temp>maxi){
							maxi=temp;
							bx=i;
							by=j;
							dir=1;
						}
					}
					if (j+2<7&&ma[i][j+1]==1&&ma[i][j+2]==0){
						int temp=point[i][j+2]*100+point[i][j];
						if (temp>maxi){
							maxi=temp;
							bx=i;
							by=j;
							dir=2;
						}
					}
					if (j-2>=0&&ma[i][j-1]==1&&ma[i][j-2]==0){
						int temp=point[i][j-2]*100+point[i][j];
						if (temp>maxi){
							maxi=temp;
							bx=i;
							by=j;
							dir=3;
						}
					}
				}
			}
			if (dir==-1)break;
			if (dir==0){
				ma[bx][by]^=1;
				ma[bx+1][by]^=1;
				ma[bx+2][by]^=1;
			}
			else if (dir==1){
				ma[bx][by]^=1;
				ma[bx-1][by]^=1;
				ma[bx-2][by]^=1;
			}
			else if (dir==2){
				ma[bx][by]^=1;
				ma[bx][by+1]^=1;
				ma[bx][by+2]^=1;
			}
			else if (dir==3){
				ma[bx][by]^=1;
				ma[bx][by-1]^=1;
				ma[bx][by-2]^=1;
			}
		}
		int tot=0;
		for (int i=0;i<7;i++){
			for (int j=0;j<7;j++){
				tot+=(ma[i][j]==1)*point[i][j];
			}
		}
		printf ("%d\n",tot);
	}
	printf ("END OF OUTPUT\n");
}
//UVA 462 Bridge Hand Evaluator
#include <bits/stdc++.h>
using namespace std;
int main(){
	char rem[500];
	while (scanf("%[^\n]",rem)!=EOF){
		getchar();
		int count[4][5];
		int scoun[4];
		int stop=0;
		for (int i=0;i<4;i++){
			for (int j=0;j<5;j++){
				count[i][j]=0;
			}
			scoun[i]=0;
		}
		int l=strlen(rem);
		for (int i=0;i<l;i+=3){
			int x=0,y;
			if (rem[i]=='A')x=4;
			else if (rem[i]=='K')x=3;
			else if (rem[i]=='Q')x=2;
			else if (rem[i]=='J')x=1;
			if (rem[i+1]=='S')y=0;
			else if (rem[i+1]=='H')y=1;
			else if (rem[i+1]=='D')y=2;
			else if (rem[i+1]=='C')y=3;
			count[y][x]++;
			scoun[y]++;
		}
		int tot=0;
		for (int i=0;i<4;i++){
			if (count[i][4]>0||(count[i][3]>0&&scoun[i]-count[i][3]>0)||(count[i][2]>0&&scoun[i]-count[i][2]>1)){
				stop|=(1<<i);
			}
		}
		for (int i=0;i<4;i++){
			for (int j=0;j<5;j++){
				tot+=count[i][j]*j;
			}
		}
		for (int i=0;i<4;i++){
			for (int j=1;j<4;j++){
				if (count[i][j]==0)continue;
				tot-=(scoun[i]-count[i][j])<(4-j);
			}
		}
		if (stop==(1<<4)-1&&tot>=16){
			printf ("BID NO-TRUMP\n");
		}
		else{
			for (int i=0;i<4;i++){
				if (scoun[i]==2)tot++;
				else if (scoun[i]==1)tot+=2;
				else if (scoun[i]==0)tot+=2;
			}
			if (tot<14)printf ("PASS\n");
			else{
				int maxi=0;
				for (int i=1;i<4;i++){
					if (scoun[i]>scoun[maxi])
						maxi=i;
				}
				printf ("BID ");
				if (maxi==0)printf ("S\n");
				else if (maxi==1)printf ("H\n");
				else if (maxi==2)printf ("D\n");
				else if (maxi==3)printf ("C\n");
			}
		}
	}
}
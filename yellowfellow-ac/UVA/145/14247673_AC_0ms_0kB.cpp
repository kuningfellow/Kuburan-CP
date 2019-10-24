//UVA 145 Gondwanaland Telecom
#include <bits/stdc++.h>
using namespace std;
int main(){
	int cost[5][3]={10,6,2,25,15,5,53,33,13,87,47,17,144,80,30};
	while (1<2){
		int tot[3]={0,0,0};
		char rem[50];
		scanf("%s",rem);
		if (rem[0]=='#')break;
		int type=rem[0]-'A';
		char ram[500];
		scanf("%s",ram);
		int h,m,h2,m2;
		scanf("%d%d%d%d",&h,&m,&h2,&m2);
		if (h==24)h=0;
		int fir=1;
		while (fir||h!=h2||m!=m2){
			if (h>=8&&h<18)tot[0]++;
			else if (h>=18&&h<22)tot[1]++;
			else tot[2]++;
			m++;
			if (m==60){
				h++;
				m=0;
			}
			fir=0;
			if (h==24)h=0;
		}
		double gtot=0;
		for (int i=0;i<3;i++)gtot+=tot[i]*cost[type][i];
		printf ("%10s%6d%6d%6d%3s%8.2f\n",ram,tot[0],tot[1],tot[2],rem,gtot/100);
	}
}
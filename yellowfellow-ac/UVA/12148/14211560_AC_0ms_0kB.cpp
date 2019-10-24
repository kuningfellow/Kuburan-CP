//UVA 12148 Electricity
#include <bits/stdc++.h>
using namespace std;
bool leap(int y){
	if (y%400==0||(y%4==0&&y%100!=0))return 1;
	return 0;
}
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	while (1<2){
		int n;
		cin>>n;
		if (n==0)break;
		int tot=0;
		int cons=0;
		int pd=-1,pm=-1,py=-1,pp=-1;
		int d,m,y,p;
		while (n--){
			cin>>d>>m>>y>>p;
			d--;
			m--;
			if (d==pd&&m==pm&&y==py){
				cons++;
				tot+=p-pp;
			}
			pd=d;
			pm=m;
			py=y;
			pp=p;
			pd++;
			if (pm==1&&leap(py)&&pd==29){
				pd=0;
				pm++;
			}
			else if ((pm!=1||!leap(py))&&pd==month[pm]){
				pd=0;
				pm++;
			}
			if (pm==12){
				pm=0;
				py++;
			}
		}
		printf ("%d %d\n",cons,tot);
	}
}
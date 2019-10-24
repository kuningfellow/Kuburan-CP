#include <bits/stdc++.h>
using namespace std;
double widt=3.66;
double leng=52.5;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		double xb,yb,xg,yg,r;
		cin>>xb>>yb>>xg>>yg>>r;
		double dist1=sqrt((xb-xg)*(xb-xg)+(yb-yg)*(yb-yg));
		double range=asin(r/dist1);
		double deg1=atan((yg-yb)/(xg-xb));
		double deg2=atan((widt-yb)/(leng-xb));
		double deg3=atan((-widt-yb)/(leng-xb));
		if (deg2>deg1+range||deg3<deg1-range){
			printf ("Goal!\n");
		}
		else printf ("No goal...\n");
	}
}
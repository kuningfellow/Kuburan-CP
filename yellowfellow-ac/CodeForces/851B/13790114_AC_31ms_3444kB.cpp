#include <bits/stdc++.h>
using namespace std;
int main(){
	double x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	double dist=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	double dist3=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	double v1=x2-x1;
	double v2=y2-y1;
	double u1=x3-x2;
	double u2=y3-y2;
	if (dist==dist3&&v1*u2-v2*u1!=0){
		printf ("Yes\n");
	}
	else printf ("No\n");
}
#include <bits/stdc++.h>
using namespace std;
double X,Y;
double abso(double a){
	if (a<0)return -a;
	return a;
}
double dist(double x1, double y1, double x2, double y2){
	double lx=x2-x1;
	double ly=y2-y1;
	double len=sqrt(lx*lx+ly*ly);
	double px=X-x1;
	double py=Y-y1;
	double cros=px*ly-py*lx;
	double crawl=(px*lx+py*ly)/len;
	if (crawl>len||crawl<0){
		return min(sqrt((X-x1)*(X-x1)+(Y-y1)*(Y-y1)),sqrt((X-x2)*(X-x2)+(Y-y2)*(Y-y2)));
	}
	else{
		return abso((double)cros/len);
	}
}
void getpos(double x1, double y1, double x2, double y2){
	double lx=x2-x1;
	double ly=y2-y1;
	double len=sqrt(lx*lx+ly*ly);
	double px=X-x1;
	double py=Y-y1;
	double crawl=(px*lx+py*ly)/len;
	if (crawl<0){
		printf ("%.4f\n%.4f\n",(double)x1,(double)y1);
	}
	else if (crawl>len){
		printf ("%.4f\n%.4f\n",(double)x2,(double)y2);
	}
	else{
		printf ("%.4f\n%.4f\n",(double)x1+lx*crawl/len+1e-9,(double)y1+ly*crawl/len+1e-9);
	}
}
int main(){
	double a,b,c,d;
	double sa,sb,sc,sd;
	double maxi;
	double temp;
	int n;
	while (scanf("%lf",&X)!=EOF){
		scanf("%lf",&Y);
		scanf("%d",&n);
		scanf("%lf%lf",&a,&b);
		maxi=(1<<28);
		for (int i=0;i<n;i++){
			scanf("%lf%lf",&c,&d);
			temp=dist(a,b,c,d);
			if (temp<maxi){
				maxi=temp;
				sa=a;
				sb=b;
				sc=c;
				sd=d;
			}
			a=c;
			b=d;
		}
		getpos(sa,sb,sc,sd);
	}
	return 0;
}
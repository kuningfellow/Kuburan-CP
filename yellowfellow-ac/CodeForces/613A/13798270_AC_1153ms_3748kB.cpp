#include <bits/stdc++.h>
using namespace std;
double x,y;
double abso(double a){
	if (a<0)return -a;
	return a;
}
double dist(double x1, double y1, double x2, double y2){
	double u1=x2-x1;
	double u2=y2-y1;
	double v1=x-x1;
	double v2=y-y1;
	double len=sqrt(u1*u1+u2*u2);
	double crawl=(u1*v1+u2*v2)/len;
	if (crawl<0||crawl>len){
		return -1;
	}
	else{
		return abso((u1*v2-u2*v1)/len);
	}
}
int lcnt;
int rcnt;
int cross;
void side(double x1, double y1, double x2, double y2){
	double u1=x2-x1;
	double u2=y2-y1;
	double v1=x-x1;
	double v2=y-y1;
	double res=(u1*v2-u2*v1);
	double len=sqrt(u1*u1+u2*u2);
	double crawl=(u1*v1+u2*v2)/len;
	if (res>-1e-9&&res<1e-9&&crawl>=0&&crawl<=len){
		cross=1;
	}
	else if (res>0){
		rcnt++;
	}
	else if (res<0){
		lcnt++;
	}
}
int main(){
	int n;
	cross=0;
	lcnt=0;
	rcnt=0;
	double a,b,pa,pb;
	cin>>n>>x>>y;
	double fuhrer=0;
	double nearer=(1<<28);
	double temp;
	double fa,fb;
	for (int i=0;i<n;i++){
		cin>>a>>b;
		temp=sqrt((a-x)*(a-x)+(b-y)*(b-y));
		if (temp>fuhrer){
			fuhrer=temp;
		}
		if (temp<nearer){
			nearer=temp;
		}
		if (i!=0){
			side(pa,pb,a,b);
			temp=dist(pa,pb,a,b);
			if (temp>0&&temp<nearer){
				nearer=temp;
			}
		}
		else{
			fa=a;
			fb=b;
		}
		pa=a;
		pb=b;
	}
	side(a,b,fa,fb);
	temp=dist(a,b,fa,fb);
	if (temp>0&&temp<nearer){
		nearer=temp;
	}
	if (lcnt!=0&&rcnt!=0&&cross==0){
		printf ("%.12f\n",acos(-1)*(fuhrer*fuhrer-nearer*nearer));
	}
	else printf ("%.12f\n",(double)0);
}